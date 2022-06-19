#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "point.h"

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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
         for(int i = 0; i < p.size();i++){
             Point *point = p[i];
             point->draw(&painter);
             if (i)
                 point->UnitedPoints(&painter,p[i-1]);

         }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint clickPoint;
    clickPoint.setX(event->x());
    clickPoint.setY(event->y());
    for(int i = 0; i < p.size();i++)
     {
        if(p[i]->distance2(clickPoint) < 6){
            p[i]->setPressed(true);
            break;
         }
     }

    Point *point = new Point(event->x(),event->y(),3,1);
    p.append(point);

    repaint();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    for(int i = 0; i < p.size(); i++){
        if(p[i]->getPressed()){
            p[i]->setX(event->x());
            p[i]->setY(event->y());
            p[i]->setPressed(false);
            break;
        }
    }
    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    for(int i = 0; i < p.size(); i++){
        if(p[i]->getPressed())
        {
            p[i]->setX(event->x());
            p[i]->setY(event->y());
        }
    }
    repaint();

}
