#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QVector>

class Snakebody : public QWidget
{
    Q_OBJECT
public:
    explicit Snakebody(QWidget *parent = nullptr);

void paintEvent(QPaintEvent *);
void keyPressEvent(QKeyEvent *);
int modx(int);
int mody(int);
    int V= 100;
    int hod = 0;
    int hod1 = 0;
   QVector<int> x1;
   QVector<int> y1;
    int x= 50;
    int y= 10;
    int lng = 5;
    bool eat =0;
    int yumx=0;
    int yumy=0;
   QVector<int> napr;
   QString f="SCORE:";



signals:
    void speedup();
    void speedup2(int);
    void scoreup(QString);


public slots:
    void movin();

};

#endif // SNAKEBODY_H
