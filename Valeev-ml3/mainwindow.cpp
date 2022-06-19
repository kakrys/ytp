#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include "rect.h"
#include <QMessageBox>


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
    if (clickcnt == 1)
    {
        tempX1=event->x();
        tempY1=event->y();
    }
    else if (clickcnt == 2)
    {
        tempX2=event->x();
        tempY2=event->y();
        Rect *r;
        r = new Rect (tempX1, tempX2, tempY1, tempY2);
        tempX1 = r->getX1();
        tempX2 = r->getX2();
        tempY1 = r->getY1();
        tempY2 = r->getY2();
        delete r;
    }
    else
    {
        Rect *r;
        r = new Rect (tempX1, tempX2, tempY1, tempY2);
        QMessageBox Box;
        if(r->contains(event->x(),event->y()))
        {
            Box.setWindowTitle("Попадание");
            Box.setText("Попали");
            Box.exec();
        } else
        {
            Box.setWindowTitle("Попадание");
            Box.setText("Не попали");
            Box.exec();
        }
        delete r;
    }
    clickcnt++;
    repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
    if(clickcnt>2)
    {
        painter.drawRect(tempX1,tempY1,abs(tempX1-tempX2),abs(tempY1-tempY2));
    }
}
