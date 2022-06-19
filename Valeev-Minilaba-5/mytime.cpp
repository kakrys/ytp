#include "mytime.h"
#include <QDebug>

Mytime::Mytime()
    :Mytime(0,0)
{

}

Mytime::Mytime(int h, int m)
{
    if(m >= 60)
    {
     int tempDays = m / 60;
     h += tempDays;
     m -= tempDays * 60;
    }

    this->h = h < 24 ? h : h - 24 * (h / 24);
    this->m = m;
}

Mytime::Mytime(std::string o)
    //:h(h),m(m)
{
    int h = std::stoi(o.substr(0,2));
    int m = std::stoi(o.substr(3,2));
    if(m >= 60)
    {
     int tempDays = m / 60;
     h += tempDays;
     m -= tempDays * 60;
    }

    this->h = h < 24 ? h : h - 24 * (h / 24);
    this->m = m;
}

Mytime Mytime::operator +(int o)
{
    int min = this->m + o;
    this->h = h < 24 ? h : h%24;
    return Mytime (this->h,min);
}

int Mytime::operator -(Mytime o)
{
    int minutes1 = o.h*60+o.m;
    int minutes2 = this->h * 60 + this->m;
    return (abs(minutes2-minutes1));
}


void Mytime::print()
{
    if (h<10 && m>10) qDebug("0%d:%d",h,m);
    else if (m<10 && h>10) qDebug("%d:0%d",h,m);
    else if (h<10 && m<10) qDebug("0%d:0%d",h,m);
    else if (h>9 && m>9) qDebug("%d:%d",h,m);

}
