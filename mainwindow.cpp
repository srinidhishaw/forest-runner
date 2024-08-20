#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QRect>
#include <QEasingCurve>

bool keys[10];
bool key[9];
int yval=0,xval=0;
bool jump,down;
bool left1=true;
bool right1=true;
bool m_bFirstRelease;
QList<QLabel *> walls;
bool collision(int x, int y, int width, int height);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(myTimer()));
    timer->start(20);

    walls.append(ui->wall2);

    walls.append(ui->wall4);


}
MainWindow::~MainWindow()
{
    delete ui;
}
QSet<Qt::Key> keysPressed;
void MainWindow::keyPressEvent(QKeyEvent* event){
    for(int c=0;c<8;c++)keys[c]=false;
    if (event->key()==Qt::Key_W)keys[0]=true;
    if (event->key()==Qt::Key_A)keys[1]=true;
    if (event->key()==Qt::Key_S)keys[2]=true;
    if (event->key()==Qt::Key_D)keys[3]=true;
    if (event->key()==Qt::Key_Left)keys[4]=true;
    if (event->key()==Qt::Key_Right)keys[5]=true;
    if (event->key()==Qt::Key_Up)keys[6]=true;
    if (event->key()==Qt::Key_Down)keys[7]=true;

}
void MainWindow::keyReleaseEvent(QKeyEvent* event){
    for(int c=0;c<8;c++)key[c]=false;
    if (event->key()==Qt::Key_W)key[0]=true;
    if (event->key()==Qt::Key_A)key[1]=true;
    if (event->key()==Qt::Key_S)key[2]=true;
    if (event->key()==Qt::Key_D)key[3]=true;
    if (event->key()==Qt::Key_Left)key[4]=true;
    if (event->key()==Qt::Key_Right)key[5]=true;
    if (event->key()==Qt::Key_Up)key[6]=true;
    if (event->key()==Qt::Key_Down)key[7]=true;

}

void MainWindow::myTimer(){
int t=0;
    if(keys[0]){
        if(ui->label->y()-(t*t)>=0 && ui->label->x()+0.8<=380 && !collision(ui->label->x(),ui->label->y()-5,ui->label->width(),ui->label->height())){
        t=ui->label->x()+0.8;
            ui->label->move(ui->label->x()+0.8,ui->label->y()-(t*t));
        }
    }
    if (keys[2]){
        if(ui->label->x()-5<=380 && !collision(ui->label->x()-5,ui->label->y(),ui->label->width(),ui->label->height())){
            ui->label->move(ui->label->x(),ui->label->y()+5);
        }
    }
    if(keys[1]){
        if(ui->label->x()-5<=380 && !collision(ui->label->x()-5,ui->label->y(),ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x()-5,ui->label->y());
        }
    }
    if(keys[3]){
        if(ui->label->y()-5>=0 && !collision(ui->label->x(),ui->label->y()-5,ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x(),ui->label->y()-5);
        }
    }
    if (keys[1] && keys[0]){
        if(ui->label->y()-5>=0 && !collision(ui->label->x(),ui->label->y()-5,ui->label->width(),ui->label->height())){
            ui->label->move(ui->label->x()+3,ui->label->y()-5);
        }
    }
    if (keys[10] && jump==false){
        yval=ui->label->y();
        xval=ui->label->x();
        if(ui->label->y()-5>=0 && !collision(ui->label->x()+2,ui->label->y()-5,ui->label->width(),ui->label->height())){
         ui->label->move(ui->label->x()+3,ui->label->y()-5);
        }
    }




    if(keys[4]){
        if(ui->label->x()-5>=0 && ui->label->y()+6<=245 && !collision(ui->label->x()-5,ui->label->y()+6,ui->label->width(),ui->label->height())){
        ui->label->move(ui->label->x()-5,ui->label->y()+6);
        }
    }
    if(keys[5]){
        if(ui->label->x()+5<=380 && ui->label->y()+6<=0 && !collision(ui->label->x(),ui->label->y()-5,ui->label->width(),ui->label->height())){
        ui->label->move(ui->label->x()+5,ui->label->y()+6);
        }
    }


    if(keys[6]){
        if(ui->label->x()-5>=0 && !collision(ui->label->x()-5,ui->label->y(),ui->label->width(),ui->label->height())){
       ui->label->move(ui->label->x()-5,ui->label->y());
        }
    }
    if(keys[7]){
        if(ui->label->x()+5<=380 && !collision(ui->label->x()+5,ui->label->y(),ui->label->width(),ui->label->height())){
       ui->label->move(ui->label->x()+5,ui->label->y());
        }
    }
}



bool collision(int x, int y, int width, int height){
        bool hit=false;
        QRect r1(x,y,width,height),r2;

        for(int c=0;c<2;c++){
            r2.setX(walls.at(c)->x());
            r2.setY(walls.at(c)->y());
            r2.setWidth(walls.at(c)->width());
            r2.setHeight(walls.at(c)->height());
            if(r1.intersects(r2))hit= true;
        }
        return hit;
 }

