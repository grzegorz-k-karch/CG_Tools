#include "mainwindow.h"
#include "glwidget.h"
#include "clickablelabel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPalette>
#include <QColorDialog>
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

    ClickableLabel *lightColorBox = new ClickableLabel();
    lightColorBox->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    lightColorBox->setAutoFillBackground(true);
    lightColorBox->setLineWidth(3);
    lightEditorLayout->addWidget(lightColorBox);
    QPalette *palette = new QPalette;
    palette->setColor(QPalette::Background,Qt::blue);
    lightColorBox->setPalette(*palette);

    QColorDialog *colorDialog = new QColorDialog(this);
    connect(lightColorBox,SIGNAL(clicked()),colorDialog,SLOT(show()));

    mainLayout->addLayout(lightEditorLayout);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{

}
