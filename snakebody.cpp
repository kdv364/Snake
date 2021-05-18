#include "snakebody.h"
#include "mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <ctime>
#include <QLabel>
#include <QWidget>

Snakebody::Snakebody(QWidget *parent) : QWidget(parent)
{QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Snakebody::movin);
    connect(this, &Snakebody::speedup, timer, &QTimer::stop );
   //connect (this, &Snakebody::speedup, timer, &QTimer::start );
    timer->start(V);
     QWidget::setFocusPolicy(Qt::ClickFocus);
     napr.append(1);
     napr.append(1);
    hod++;
connect(this, SIGNAL(speedup2(int)), timer, SLOT(start(int)) );






}

void Snakebody::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QBrush brush(Qt::black, Qt::SolidPattern);
    brush.setColor(Qt::black);


    switch (napr[hod]) {case 1:
            painter.fillRect(x=modx(x+10),y, 10, 10, brush);
            napr.append(1);
            hod++;
            break;
        case 2:
            painter.fillRect(x,y=mody(y-10), 10, 10, brush);
            napr.append(2);
            hod++;
            break;
        case 3:
            painter.fillRect(x=modx(x-10),y, 10, 10, brush);
            napr.append(3);
            hod++;
            break;
        case 4:
            painter.fillRect(x,y=mody(y+10), 10, 10, brush);
            napr.append(4);
            hod++;
            break;

        }
    hod1 = hod-1;
    x1.clear();
    y1.clear();
    x1.append(x);
    y1.append(y);

    for (int i=0; i < lng; i++) {

        switch (napr[hod1]) {case 1:
                x1.append(modx(x1[i]-10));
                y1.append(y1[i]);
                painter.fillRect(x1[i+1],y1[i+1], 10, 10, brush);
if (hod1 !=0)
                {hod1--;}
                break;
            case 2:
            x1.append(x1[i]);
            y1.append(mody(y1[i]+10));
            painter.fillRect(x1[i+1],y1[i+1], 10, 10, brush);
if (hod1 !=0)
           {hod1--;}
                break;
            case 3:
            x1.append(modx(x1[i]+10));
            y1.append(y1[i]);
            painter.fillRect(x1[i+1],y1[i+1], 10, 10, brush);
if (hod1 !=0)
            {hod1--;}
                break;
            case 4:
            x1.append(x1[i]);
            y1.append(mody(y1[i]-10));
            painter.fillRect(x1[i+1],y1[i+1], 10, 10, brush);
if (hod1 !=0)
            {hod1--;}
                break;

        }}
    if (x==yumx && y==yumy) {
        eat=0;
        lng++;
        f="SCORE:"+QString::number(lng-5);
        emit scoreup(f);
    }


srand( time( 0 ) );
    if (eat)
    {painter.fillRect(yumx,yumy, 10, 10, brush);
    eat=1;}
    else {
    yumx=(rand()% 91)*10;
    yumy=(rand()% 49)*10;
    eat=1;
    }
    for (int i=1; i < lng; i++) {
        if (x1[i]==yumx && y1[i]==yumy) {
            eat=0;
            lng++;
        }
        if(x==x1[i] && y==y1[i])
        {
            painter.fillRect(0,0, width(), height(), brush);
             hod = 0;
             hod1 = 0;
              x= 50;
              y= 10;
              lng = 5;
              eat =0;
              yumx=0;
              yumy=0;
              x1.clear();
              y1.clear();
              napr.clear();
              napr.append(1);
              napr.append(1);
             hod++;


        }
    }




}
void Snakebody::keyPressEvent(QKeyEvent *paintEvent) {
    int key = paintEvent->key();

    switch (key) {
    case Qt::Key_Up:
        if (napr[hod] != 2 && napr[hod] != 4)

           { napr[hod]= 2;}
            break;

    case Qt::Key_Left:
        if (napr[hod] != 3 && napr[hod] != 1)
          {  napr[hod]= 3;}
            break;

    case Qt::Key_Down:
        if (napr[hod] != 4 && napr[hod] != 2)
        { napr[hod]= 4;}
            break;

    case Qt::Key_Right:
        if (napr[hod] != 1 && napr[hod] != 3)
             {napr[hod]= 1;}
            break;
    case Qt::Key_Space:
        emit speedup();
        V=V/2;
        emit speedup2(V);
        break;



    }

}

void Snakebody::movin() {QWidget::repaint();

}
int Snakebody::modx(int a) {if (a<0)
                           a=width()-11;
                           if (a>width())
                           a=0+10;
                           return a;}
int Snakebody::mody(int a) {if (a<0)
                           a=height()-11;
                           if (a>height())
                           a=0+10;
                           return a;}
