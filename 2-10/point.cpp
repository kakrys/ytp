#include "point.h"
#include <QPainter>

Point::Point(int x, int y, int size, int width)
    : x(x),y(y),size(size),width(width)
{

}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}

void Point::draw(QPainter *painter){
    int x = this->getX();
    int y = this->getY();
    int size = this->getSize();
    int width = this->getWidth();
    QPen pen;
    pen.setWidth(width);
    painter->setPen(pen);
    painter->drawLine(x - size,y,x + size,y);
    painter->drawLine(x,y - size ,x,y + size);
}

void Point::UnitedPoints(QPainter *painter, Point *point)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    painter->drawLine(point->getX(),point->getY(),this->getX(),this->getY());
}

float Point::distance2(const QPoint &point)
{
    float distanse = ((point.x() - this->getX()) * (point.x() - this->getX())) + ((point.y() - this->getY()) * (point.y() - this->getY()));
    return distanse;
}

bool Point::getPressed() const
{
    return pressed;
}

void Point::setPressed(bool newPressed)
{
    pressed = newPressed;
}
