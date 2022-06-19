#ifndef MYTIME_H
#define MYTIME_H
#include <string>
#include <iostream>


class Mytime
{
public:
    Mytime();
    Mytime(int h, int m);
    Mytime(std::string time);
    Mytime operator +(int o);
    int operator - (Mytime o);
    void print();
private:
    int h,m;
};

#endif // MYTIME_H
