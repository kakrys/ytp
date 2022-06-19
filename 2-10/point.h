#ifndef POINT_H
#define POINT_H
class QPainter;
class QPoint;
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
    void UnitedPoints (QPainter *painter,Point *point);
    float distance2(const QPoint &point);

    bool getPressed() const;
    void setPressed(bool newPressed);

private:
   int x,y,size,width;
   bool pressed;
};

#endif // POINT_H
