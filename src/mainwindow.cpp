#include "mainwindow.h"
#include "glwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPalette>
#include <QPushButton>

MainWindow::MainWindow()
{
    glwidget = new GLWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(glwidget);

    QHBoxLayout *lightEditorLayout = new QHBoxLayout;

    QLabel *lightColorLabel = new QLabel(this);
    lightColorLabel->setText("Light color");
    lightEditorLayout->addWidget(lightColorLabel);

    QLabel *lightColorBox = new QLabel(this);
    lightColorBox->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    lightColorBox->setAutoFillBackground(true);
    lightColorBox->setLineWidth(3);

    QPalette *palette = new QPalette;
    palette->setColor(QPalette::Background,Qt::blue);
    lightColorBox->setPalette(*palette);

    lightEditorLayout->addWidget(lightColorBox);

    QPushButton *colorButton = new QPushButton(this);
    colorButton->setFlat(true);

    lightEditorLayout->addWidget(colorButton);
//http://qt-project.org/wiki/Make-a-QLabel-Clickable

    mainLayout->addLayout(lightEditorLayout);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
