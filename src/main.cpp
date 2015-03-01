#include <QApplication>

#include "mainwindow.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainwindow;
    mainwindow.resize(800,600);
    mainwindow.show();

    return app.exec();
}

