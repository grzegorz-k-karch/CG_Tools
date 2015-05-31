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
    QVBoxLayout *mainLayout = new QVBoxLayout;

    GLWidget *glwidget = new GLWidget;
    mainLayout->addWidget(glwidget);

    QHBoxLayout *lightEditorLayout = new QHBoxLayout;

    // create label for the light control -----------------------------------
    QLabel *lightColorLabel = new QLabel(this);
    lightColorLabel->setText("Light color");
    lightEditorLayout->addWidget(lightColorLabel);

    // create color box that can be clicked to change light color -----------
    ClickableLabel *lightColorBox = new ClickableLabel(this);
    lightColorBox->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
    lightColorBox->setAutoFillBackground(true);
    lightColorBox->setLineWidth(3);
    lightColorBox->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));
    lightEditorLayout->addWidget(lightColorBox);

    // color dialog will open after clicking color box ----------------------
    QColorDialog *colorDialog = new QColorDialog(this);
    connect(lightColorBox,SIGNAL(clicked()),colorDialog,SLOT(show()));
    connect(colorDialog,SIGNAL(colorSelected(QColor)),lightColorBox,SLOT(setColor(QColor)));

    // light control sets the light color in the shader ---------------------
    LightControl *lightControl = new LightControl(this);
    glwidget->setLightControl(lightControl);
    connect(lightColorBox,SIGNAL(colorChanged(QColor)),lightControl,SLOT(setLightColor(QColor)));
    mainLayout->addLayout(lightEditorLayout);

    // set main layout as the central widget --------------------------------
    setCentralWidget(new QWidget);
    centralWidget()->setLayout(mainLayout);

    // create file menu -----------------------------------------------------
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *action_openFile;
    action_openFile = new QAction("Open File...", this);
    action_openFile->setShortcuts(QKeySequence::Open);
    action_openFile->setStatusTip(tr("Open an existing file"));
    connect(action_openFile, SIGNAL(triggered()), this, SLOT(fileOpen()));
    connect(this, SIGNAL(fileSelected(QString)), glwidget, SLOT(LoadMesh(QString)));
    fileMenu->addAction(action_openFile);

    QAction *action_quit;
    action_quit = new QAction("Quit", this);
    action_quit->setShortcuts(QKeySequence::Quit);
    action_quit->setStatusTip(tr("Quit program"));
    connect(action_quit, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(action_quit);

    // create the status bar at the bottom of the window
    statusBar();
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
