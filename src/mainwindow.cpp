#include "mainwindow.h"
#include "glwidget.h"
#include "clickablelabel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPalette>
#include <QColorDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include "lightcontrol.h"
#include <iostream>

MainWindow::MainWindow()
{
    glwidget = new GLWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(glwidget);

    QHBoxLayout *lightEditorLayout = new QHBoxLayout;

    QLabel *lightColorLabel = new QLabel(this);
    lightColorLabel->setText("Light color");
    lightEditorLayout->addWidget(lightColorLabel);

    QPalette *palette = new QPalette;
    palette->setColor(QPalette::Background,Qt::white);

    ClickableLabel *lightColorBox = new ClickableLabel(this);
    lightColorBox->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    lightColorBox->setAutoFillBackground(true);
    lightColorBox->setLineWidth(3);
    lightColorBox->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));
    lightEditorLayout->addWidget(lightColorBox);

    lightColorBox->setPalette(*palette);
    delete palette;

    QColorDialog *colorDialog = new QColorDialog(this);
    connect(lightColorBox,SIGNAL(clicked()),colorDialog,SLOT(show()));
    connect(colorDialog,SIGNAL(colorSelected(QColor)),lightColorBox,SLOT(setColor(QColor)));

    LightControl *lightControl = new LightControl(this);
    glwidget->setLightControl(lightControl);
    connect(lightColorBox,SIGNAL(colorChanged(QColor)),lightControl,SLOT(setLightColor(QColor)));

    mainLayout->addLayout(lightEditorLayout);
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);


    fileMenu = menuBar()->addMenu(tr("&File"));
    helpMenu = menuBar()->addMenu(tr("&Help"));

    QAction *action;

    action = new QAction("Open File...", this);
    action->setShortcuts(QKeySequence::Open);
    action->setStatusTip(tr("Open an existing file"));
    connect(action, SIGNAL(triggered()), this, SLOT(fileOpen()));
    fileMenu->addAction(action);

    (void)statusBar();

    connect(this, SIGNAL(fileSelected(QString)), glwidget, SLOT(LoadMesh(QString)));
}

MainWindow::~MainWindow()
{

}

void MainWindow::fileOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) {
        emit fileSelected(fileName);
    }
}
