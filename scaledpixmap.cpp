#include "scaledpixmap.h"

#include <QPainter>

ScaledPixmap::ScaledPixmap()
{

}

void ScaledPixmap::showLabels()
{
//    for (int var = 0; var < 10; ++var) {
//        QLabel* lib1=new QLabel("seeks"+QString::number(var),this);
//        lList.append(lib1);
//    }
//    for (int var = 0; var < 10; ++var) {
//        lList.at(var)->move(10*var,20*var);
//    }
    QVBoxLayout* QBlayout=new QVBoxLayout(this);
    QPushButton* testButton=new QPushButton(this);
    QCheckBox* testbox=new QCheckBox(this);
    testButton->setCheckable(true);
    connect(testbox,SIGNAL(toggled(bool)),testButton,SLOT(setChecked(bool)));
    connect(testButton,SIGNAL(clicked(bool)),this,SLOT(buttMessage()),Qt::UniqueConnection);
    QBlayout->addWidget(testbox);
    QBlayout->addWidget(testButton);
}

void ScaledPixmap::setScaledPixmap(const QPixmap &pixmap)
{
    hockeyImage=pixmap;
    update();
}

void ScaledPixmap::loadPixmapData(const QString &path)
{
    QPixmap pixmap(path);
    const bool loaded=!pixmap.isNull();
    if(loaded){
        setScaledPixmap(pixmap);
    }
}

void ScaledPixmap::buttMessage() const
{
    qDebug()<<"ASS\n";
}

void ScaledPixmap::displayWidget()
{
    test =new QLabel("Teeeest",this);
//    test->move(QCursor::pos()-this->size());
    QPoint p=QPoint(mapFromGlobal(QCursor::pos())-this->pos());
    test->move(p);
    qDebug()<<"Cursor: "<<QCursor::pos()<<"this.pos(): "<<this->pos()<<"deverse "<<mapFromGlobal(QCursor::pos())-this->pos();
    test->show();



}

//передаем ивет объекта
void ScaledPixmap::paintEvent(QPaintEvent * const event)
{
    //Класс рисования этого виджета
    QPainter painter(this);
    if(!hockeyImage.isNull())
    {
        //Класс для хранения позиции виджета
        QPoint centerPoint(0,0);
        //Текущий размер виджетта
        QSize scaledSize=size();
        //Устанавливаем размер картинки
        QPixmap scaledPixmap=hockeyImage.scaled(scaledSize,Qt::KeepAspectRatio);
        //
        centerPoint.setX((scaledSize.width()-scaledPixmap.width())/2);

        centerPoint.setY((scaledSize.height()-scaledPixmap.height())/2);
        qDebug()<<QString::number(centerPoint.x())<<"/"<<QString::number(centerPoint.y());
        qDebug()<<"Размер картинки"<<size();
        painter.drawPixmap(centerPoint,scaledPixmap);
    }
//    QLabel::paintEvent(event);
}



void ScaledPixmap::mousePressEvent(QMouseEvent *event)
{
    if(Qt::RightButton==event->button()){
    qDebug()<<"Right button click from scaledPix";

    }

}
