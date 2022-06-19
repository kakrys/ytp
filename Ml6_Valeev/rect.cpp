#include "rect.h"
#include <QPainter>

Rect::Rect()
{

}

int Rect::getX1() const
{
    return x1;
}

int Rect::getX2() const
{
    return x2;
}


int Rect::getY1() const
{
    return y1;
}


int Rect::getY2() const
{
    return y2;
}


void Rect::ColorDraw(QPainter *painter, int color)
{
    QBrush brush (QColor(0,0,0,0));
    if (color==2) brush = QBrush(QColor(255,0,0,255));
    if (color==3) brush = QBrush(QColor(255,255,0,255));
    if (color==4) brush = QBrush(QColor(0,255,0,255));
    if (color==5) brush = QBrush(QColor(0,0,255,255));
    if (color==6) brush = QBrush(QColor(0,0,0,255));
    painter->setBrush(brush);
    painter->drawRect(x1,y1,abs(x1-x2),abs(y1-y2));
}








