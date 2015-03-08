#include "clickablelabel.h"
#include <iostream>

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
{

}

ClickableLabel::~ClickableLabel()
{

}

void ClickableLabel::mousePressEvent(QMouseEvent *event)

{
    emit clicked();    
}

void ClickableLabel::setColor(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Background,color);
    setPalette(palette);

    emit colorChanged(color);
}
