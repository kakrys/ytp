#include <QCoreApplication>
#include "mytime.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Mytime Pbegin = Mytime(15,30);
    Mytime Pend = Mytime(17,00);
    int Duration = Pend - Pbegin;
    qDebug("Длительность пары - %d",Duration);


    Mytime q = Mytime ("23:55");
    (q+10).print();


    return a.exec();
}
