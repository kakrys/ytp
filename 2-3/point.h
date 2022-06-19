#ifndef POINT_H
#define POINT_H
class QPainter;

class Point
{
public:
    Point(int x=0,int y=0,int size=3,int width=1);
    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getSize() const;
    void setSize(int newSize);

    int getNewsize() const;
    void setNewsize(int newNewsize);

    int getWidth() const;
    void setWidth(int newWidth);
    void draw(QPainter *painter);

private:
   int x,y,size,width;
};

#endif // POINT_H
