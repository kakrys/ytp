#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include "rect.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->modifiers() && Qt::ControlModifier) {
        if (clickcnt % 2 == 1)
        {
          tempX1=event->x();
         tempY1=event->y();
     }
     else if (clickcnt % 2 == 0)
        {
         tempX2=event->x();
         tempY2=event->y();
         Rect *r;
         r = new Rect (tempX1, tempX2, tempY1, tempY2);
         rects.append(r);
         tempX1 = r->getX1();
         tempX2 = r->getX2();
         tempY1 = r->getY1();
         tempY2 = r->getY2();
     }
     else
     {
          Rect *r;
          r = new Rect (tempX1, tempX2, tempY1, tempY2);
          rects.append(r);
     }
     clickcnt++;
     repaint();
     }

    if(!(event->modifiers() && Qt::ControlModifier))
    {
    for(Rect *r : rects){
        if(r->contains(event->x(),event->y()))
        {
            count++;
        }
    }
    qDebug("%d",count);
    }
    count=0;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
    for(Rect *r : rects)
        if(r)
            r->ColorDraw(&painter);

}
