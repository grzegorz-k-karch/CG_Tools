/*
 * http://qt-project.org/wiki/Make-a-QLabel-Clickable
 */
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    ClickableLabel(QWidget *parent = 0);
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) ;
};

#endif // CLICKABLELABEL_H
