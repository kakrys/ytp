#ifndef RECT_H
#define RECT_H
class QPainter;


class Rect
{
public:
    Rect();
    Rect(int x1,int x2,int y1,int y2){
        this->x1 = (x1<x2 ? x1 : x2);
        this->y1 = (y1<y2 ? y1 : y2);
        this->x2 = (x1>x2 ? x1 : x2);
        this->y2 = (y1>y2 ? y1 : y2);
    }
    bool contains(int x, int y){
        if(x<this->x1) return false;
        else if(x>this->x2) return false;
        else if(y<this->y1) return false;
        else if(y>this->y2) return false;
        else return true;
    }
    int getX1() const;

    int getX2() const;

    int getY1() const;

    int getY2() const;

    void ColorDraw(QPainter *painter, int color=0);

private:
    int x1,x2,y1,y2;
};

#endif // RECT_H
