/*
 * http://qt-project.org/wiki/Make-a-QLabel-Clickable
 */
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QColor>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    ClickableLabel(QWidget *parent = 0);
    ~ClickableLabel();

signals:
    void clicked();
    void colorChanged(const QColor &color);
public slots:
    void setColor(const QColor &color);
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CLICKABLELABEL_H
