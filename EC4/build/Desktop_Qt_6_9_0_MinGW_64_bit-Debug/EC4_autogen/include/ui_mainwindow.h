/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *automaticTab;
    QVBoxLayout *verticalLayoutAuto;
    QComboBox *startCombo;
    QComboBox *targetCombo;
    QPushButton *solveButton;
    QListWidget *resultList;
    QWidget *playTab;
    QVBoxLayout *verticalLayoutPlay;
    QLineEdit *nameInput;
    QComboBox *wordLengthCombo;
    QPushButton *startGameButton;
    QLabel *currentWordLabel;
    QLineEdit *nextWordInput;
    QPushButton *submitButton;
    QListWidget *moveList;
    QPushButton *hintButton;
    QLabel *hintLabel;
    QLabel *stepsRemainingLabel;
    QWidget *analyticsTab;
    QVBoxLayout *verticalLayoutAnalytics;
    QLineEdit *analyticsNameInput;
    QPushButton *analyticsLoadButton;
    QLabel *analyticsResultsLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        automaticTab = new QWidget();
        automaticTab->setObjectName("automaticTab");
        verticalLayoutAuto = new QVBoxLayout(automaticTab);
        verticalLayoutAuto->setObjectName("verticalLayoutAuto");
        startCombo = new QComboBox(automaticTab);
        startCombo->setObjectName("startCombo");

        verticalLayoutAuto->addWidget(startCombo);

        targetCombo = new QComboBox(automaticTab);
        targetCombo->setObjectName("targetCombo");

        verticalLayoutAuto->addWidget(targetCombo);

        solveButton = new QPushButton(automaticTab);
        solveButton->setObjectName("solveButton");

        verticalLayoutAuto->addWidget(solveButton);

        resultList = new QListWidget(automaticTab);
        resultList->setObjectName("resultList");

        verticalLayoutAuto->addWidget(resultList);

        tabWidget->addTab(automaticTab, QString());
        playTab = new QWidget();
        playTab->setObjectName("playTab");
        verticalLayoutPlay = new QVBoxLayout(playTab);
        verticalLayoutPlay->setObjectName("verticalLayoutPlay");
        nameInput = new QLineEdit(playTab);
        nameInput->setObjectName("nameInput");

        verticalLayoutPlay->addWidget(nameInput);

        wordLengthCombo = new QComboBox(playTab);
        wordLengthCombo->setObjectName("wordLengthCombo");

        verticalLayoutPlay->addWidget(wordLengthCombo);

        startGameButton = new QPushButton(playTab);
        startGameButton->setObjectName("startGameButton");

        verticalLayoutPlay->addWidget(startGameButton);

        currentWordLabel = new QLabel(playTab);
        currentWordLabel->setObjectName("currentWordLabel");

        verticalLayoutPlay->addWidget(currentWordLabel);

        nextWordInput = new QLineEdit(playTab);
        nextWordInput->setObjectName("nextWordInput");

        verticalLayoutPlay->addWidget(nextWordInput);

        submitButton = new QPushButton(playTab);
        submitButton->setObjectName("submitButton");

        verticalLayoutPlay->addWidget(submitButton);

        moveList = new QListWidget(playTab);
        moveList->setObjectName("moveList");

        verticalLayoutPlay->addWidget(moveList);

        hintButton = new QPushButton(playTab);
        hintButton->setObjectName("hintButton");

        verticalLayoutPlay->addWidget(hintButton);

        hintLabel = new QLabel(playTab);
        hintLabel->setObjectName("hintLabel");

        verticalLayoutPlay->addWidget(hintLabel);

        stepsRemainingLabel = new QLabel(playTab);
        stepsRemainingLabel->setObjectName("stepsRemainingLabel");

        verticalLayoutPlay->addWidget(stepsRemainingLabel);

        tabWidget->addTab(playTab, QString());
        analyticsTab = new QWidget();
        analyticsTab->setObjectName("analyticsTab");
        verticalLayoutAnalytics = new QVBoxLayout(analyticsTab);
        verticalLayoutAnalytics->setObjectName("verticalLayoutAnalytics");
        analyticsNameInput = new QLineEdit(analyticsTab);
        analyticsNameInput->setObjectName("analyticsNameInput");

        verticalLayoutAnalytics->addWidget(analyticsNameInput);

        analyticsLoadButton = new QPushButton(analyticsTab);
        analyticsLoadButton->setObjectName("analyticsLoadButton");

        verticalLayoutAnalytics->addWidget(analyticsLoadButton);

        analyticsResultsLabel = new QLabel(analyticsTab);
        analyticsResultsLabel->setObjectName("analyticsResultsLabel");

        verticalLayoutAnalytics->addWidget(analyticsResultsLabel);

        tabWidget->addTab(analyticsTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Word Ladder Game", nullptr));
        solveButton->setText(QCoreApplication::translate("MainWindow", "Solve", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(automaticTab), QCoreApplication::translate("MainWindow", "Automatic Mode", nullptr));
        startGameButton->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        currentWordLabel->setText(QCoreApplication::translate("MainWindow", "Current Word", nullptr));
        submitButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        hintButton->setText(QCoreApplication::translate("MainWindow", "Hint", nullptr));
        hintLabel->setText(QCoreApplication::translate("MainWindow", "Hint appears here", nullptr));
        stepsRemainingLabel->setText(QCoreApplication::translate("MainWindow", "Words left: ?", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(playTab), QCoreApplication::translate("MainWindow", "Play Mode", nullptr));
        analyticsNameInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter username...", nullptr));
        analyticsLoadButton->setText(QCoreApplication::translate("MainWindow", "Load Statistics", nullptr));
        analyticsResultsLabel->setText(QCoreApplication::translate("MainWindow", "Some random statistics idk", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(analyticsTab), QCoreApplication::translate("MainWindow", "Analytics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
