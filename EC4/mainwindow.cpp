//
// Created by felix on 5/28/2025.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <random>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    engine = new GameEngine(4);

    setAutoMode();
    setPlayMode();

    connect(ui->solveButton, &QPushButton::clicked, this, &MainWindow::onSolveClicked);
    connect(ui->submitButton, &QPushButton::clicked, this, &MainWindow::onSubmitClicked);
    connect(ui->hintButton, &QPushButton::clicked, this, &MainWindow::onHintClicked);
    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::onStartGameClicked);
}
MainWindow::~MainWindow() {
    delete ui;
    delete engine;
}

void MainWindow::setAutoMode() {
    auto words = engine->getAllWords();
    qDebug() << "Word count:" << words.size();  // Add this line

    ui->startCombo->clear();
    ui->targetCombo->clear();

    for (const auto& word : words) {
        QString qWord = QString::fromStdString(word);
        qDebug() << "Adding word:" << qWord;
        ui->startCombo->addItem(qWord);
        ui->targetCombo->addItem(qWord);
    }
}

void MainWindow::setPlayMode() {
    auto words = engine->getAllWords();
    QSet<int> lengths;

    for (const auto& word : words) {
        lengths.insert(static_cast<int>(word.size()));
    }

    ui->wordLengthCombo->clear();
    for (int len : std::as_const(lengths)) {
        ui->wordLengthCombo->addItem(QString::number(len));
    }
}

void MainWindow::wordsToCombo() {
    auto words = engine->getAllWords();
    ui->startCombo->clear();
    ui->targetCombo->clear();
    for (const auto& word : words) {
        QString qWord = QString::fromStdString(word);
        ui->startCombo->addItem(qWord);
        ui->targetCombo->addItem(qWord);
    }
}

void MainWindow::onSolveClicked() {
    QString start = ui->startCombo->currentText();
    QString target = ui->targetCombo->currentText();
    auto path = engine->getPath(start.toStdString(), target.toStdString());

    ui->resultList->clear();
    if (path.empty()) {
        ui->resultList->addItem("No path found.");
    } else {
        for (const auto& word : path)
            ui->resultList->addItem(QString::fromStdString(word));
    }
}

void MainWindow::onStartGameClicked() {
    username = ui->nameInput->text();
    int length = ui->wordLengthCombo->currentText().toInt();

    delete engine;
    engine = new GameEngine(length);

    wordsToCombo();

    auto words = engine->getAllWords();

    if (words.size() < 2) {
        QMessageBox::warning(this, "Error", "Not enough words loaded.");
        return;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(words.begin(), words.end(), g);

    startW = QString::fromStdString(words[0]);
    targetW = QString::fromStdString(words[1]);
    currW = startW;

    ui->currentWordLabel->setText(currW);
    moveHistory.clear();
    hintsUsed = 0;

    auto optimalPath = engine->getPath(startW.toStdString(), targetW.toStdString());
    int remainingSteps = static_cast<int>(optimalPath.size()) - 1;
    //DEBUG
    qDebug()<<"Start Word: "<<startW.toStdString()<<"\n";
    qDebug()<<"Taget Word: "<<targetW.toStdString();

    ui->stepsRemainingLabel->setText("Words left: " + QString::number(remainingSteps));
}

void MainWindow::onSubmitClicked() {
    QString attempt = ui->nextWordInput->text();
    if (!engine->isValidWord(attempt.toStdString())) {
        QMessageBox::warning(this, "Invalid", "Not a valid word.");
        return;
    }

    if (attempt.length() != currW.length()) {
        QMessageBox::warning(this, "Invalid", "Word length does not match.");
        return;
    }

    int diff = 0;
    for (int i = 0; i < attempt.length(); ++i)
        if (attempt[i] != currW[i]) ++diff;

    if (diff != 1) {
        QMessageBox::warning(this, "Invalid", "You must change exactly one letter.");
        return;
    }

    currW = attempt;
    moveHistory.append(currW);
    ui->moveList->addItem(currW);

    if (currW == targetW) {
        QMessageBox::information(this, "Success", "You reached the target word!");
        logs();
    }
}

void MainWindow::onHintClicked() {
    std::string hint = engine->getHint(currW.toStdString(), targetW.toStdString());
    if (!hint.empty()) {
        QString styledHint;
        for (int i = 0; i < static_cast<int>(hint.size()); ++i) {
            if (hint[i] != currW.toStdString()[i]) {
                styledHint += "<span style='color:red; font-weight:bold;'>" + QString(hint[i]) + "</span>";
            } else {
                styledHint += QString(hint[i]);
            }
        }

        ui->hintLabel->setText(styledHint);
        ui->hintLabel->setTextFormat(Qt::RichText);  // Enable HTML rendering
        ++hintsUsed;
    } else {
        ui->hintLabel->setText("No hint available.");
    }
}

void MainWindow::logs() {
    QFile file(username + ".csv");
    if (!file.open(QIODevice::Append | QIODevice::Text)) return;

    QTextStream out(&file);
    out << startW << "," << targetW << ","
        << QDate::currentDate().toString("yyyy-MM-dd") << ","
        << QTime::currentTime().toString("hh:mm:ss") << ","
        << moveHistory.size() << "," << hintsUsed << ","
        << moveHistory.join(" ") << "\n";
    file.close();
}

void MainWindow::showAnalytics() {
    QString user = QInputDialog::getText(this, "User Analytics", "Enter username:");
    if (user.isEmpty()) return;

    QString absolutePath = "C:/Programming/Uni/OOP_A1S2/Extra Credit/ExtraCredit4_Qt/EC4/build/Desktop_Qt_6_9_0_MinGW_64_bit-Debug/" + user + ".csv";
    QFile file(absolutePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Cannot open file at:\n" + absolutePath);
        qDebug() << "[DEBUG] Failed to open analytics file at path:" << absolutePath;
        return;
    }
    qDebug() << "File opened: " << absolutePath;


    QTextStream in(&file);
    std::set<QString> uniqueWords;
    int totalGames = 0;
    int totalMoves = 0;
    int totalHints = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList parts = line.split(',');
        if (parts.size() < 7) continue;

        totalGames++;
        totalMoves += parts[4].toInt();
        totalHints += parts[5].toInt();

        QStringList words = parts[6].split(' ', Qt::SkipEmptyParts);
        for (const auto& w : words)
            uniqueWords.insert(w.trimmed());
    }

    file.close();

    QString msg;
    msg += "User: " + user + "\n";
    msg += "Total games played: " + QString::number(totalGames) + "\n";
    msg += "Unique words used: " + QString::number(uniqueWords.size()) + "\n";
    msg += "Total moves: " + QString::number(totalMoves) + "\n";
    msg += "Total hints: " + QString::number(totalHints) + "\n";

    ui->analyticsResultsLabel->setText(msg);
}

void MainWindow::on_analyticsLoadButton_clicked() {
    showAnalytics();
}

