//
// Created by felix on 5/22/2025.
//


#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Word Ladder Game");
    window.show();

    return app.exec();
}
