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
