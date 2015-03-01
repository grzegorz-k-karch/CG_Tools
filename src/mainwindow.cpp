#include "mainwindow.h"
#include "glwidget.h"
#include <QHBoxLayout>


MainWindow::MainWindow()
{
    glwidget = new GLWidget;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(glwidget);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
