#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include "snakebody.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(scoreup(QString)),ui->label ,SLOT(setText(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changescore() {}



