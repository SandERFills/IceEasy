#include "centralwindget.h"
centralWindget::centralWindget(QWidget *parent)
    : QWidget{parent}
{

    createInterface();


}

void centralWindget::handleButton(){
}


void centralWindget::createInterface()
{
    UIgrid =new QGridLayout(this);
    setLayout(UIgrid);
    UIgrid->setColumnStretch(0,2);
    image.load("D://Qt/untitled5/resourse/hockeyArena.jpg");
    if(image.isNull()){
    qDebug("picture dont loaded");
    }
    image=image.scaled(400,400,Qt::KeepAspectRatio);
//    UIgrid->setAlignment(Qt::AlignHCenter);
    QTransform trans;
    trans.rotate(90);
    image=image.transformed(trans);
    QLabel *picL=new QLabel(this);
    picL->setPixmap(image);
    UIgrid->addWidget(picL,0,0,1,1,Qt::AlignHCenter);

}

void centralWindget::resizeImage(QSize newSize)
{
    image.scaled(newSize,Qt::KeepAspectRatioByExpanding);

}

