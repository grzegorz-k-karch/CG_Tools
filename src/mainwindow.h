#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GLWidget;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();

signals:
    void fileSelected(QString fileName);

private slots:
    void fileOpen();

private:

};

#endif // MAINWINDOW_H
