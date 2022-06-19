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
         for(int i = 0; i < cnt;i++){
             Point *point = p[i];
             point->draw(&painter);
         }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int newsize;
    if (cnt) newsize = p[cnt-1]->getSize();
    else newsize=3;
    int width;
    if (cnt < 5) width=1;
    else width=2;
    Point *point = new Point(event->x(),event->y(),newsize+1,width);
        if(cnt < 10){
            p[cnt] = point;
            cnt++;
    }
    else
        delete point;

    repaint();
}
