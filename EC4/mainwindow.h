//
// Created by felix on 5/22/2025.
//

#pragma once

#include <QMainWindow>
#include <QStringList>
#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSolveClicked();
    void onSubmitClicked();
    void onHintClicked();
    void onStartGameClicked();
    void showAnalytics();
    void on_analyticsLoadButton_clicked();

private:
    Ui::MainWindow *ui;
    GameEngine* engine = nullptr;

    QString username;
    QString startW, targetW;
    QString currW;
    QStringList moveHistory;
    int hintsUsed = 0;
    int optimalSteps = 0;

    void setAutoMode();
    void setPlayMode();
    void wordsToCombo();
    void resetPM();
    void logs();

};
