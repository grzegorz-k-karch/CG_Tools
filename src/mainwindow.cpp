#include "mainwindow.h"
#include "glwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

MainWindow::MainWindow()
{
    glwidget = new GLWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(glwidget);

    QHBoxLayout *lightEditorLayout = new QHBoxLayout;

    QLabel *lightColorLabel = new QLabel(this);
    lightColorLabel->setText("Light color");
    lightEditorLayout->addWidget(lightColorLabel);


    mainLayout->addLayout(lightEditorLayout);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
