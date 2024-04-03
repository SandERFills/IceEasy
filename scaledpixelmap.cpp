#include "scaledpixelmap.h"
#include <QtGui/QPainter>
ScaledPixelmap::ScaledPixelmap()
{
 setMinimumSize(435,640);
 resize(435,640);

}


void ScaledPixelmap::setScaledPixmap(const QPixmap &pixmap)
{
    m_pixmap = pixmap;
    m_originalSize = pixmap.size();
    update();

}

void ScaledPixelmap::loadPixmapData(const QString &path)
{
    QPixmap pixmap(path);

    if (!pixmap.isNull())
        setScaledPixmap(pixmap);

}

void ScaledPixelmap::mousePressEvent(QMouseEvent *eventMouse)
{
    if(eventMouse->button()==Qt::RightButton)
        {
            qDebug()<<"Right click from scaledPix"  ;
            qDebug()<<(eventMouse->pos())<<"Frame "<<this->frameGeometry().width()<<'/'<<this->frameGeometry().height();
            int relHeight=eventMouse->pos().x()-m_pixmap.size().width();
            int relWidth=eventMouse->pos().y()-m_pixmap.size().height();
            qDebug()<<"Pic size"<<m_pixmap.size()<<"/"<<relWidth;
            QLabel* picLabel=new QLabel("Test",this);
            picLabel->move(mapToParent(eventMouse->pos()).x(),mapToParent(eventMouse->pos()).y());
            picLabel->show();
        }
}


void ScaledPixelmap::paintEvent(QPaintEvent *event)
{
        QPainter painter(this);

    if (!m_pixmap.isNull())
    {
        QPoint centerPoint(0, 0);
        QSize scaledSize = size();

        QPixmap scaledPixmap = m_pixmap.scaled(scaledSize,  Qt::KeepAspectRatio );

        centerPoint.setX((size().width() - scaledPixmap.width()) / 2);
        centerPoint.setY((size().height() - scaledPixmap.height()) / 2);
        qDebug()<<QString::number(centerPoint.x())<<"/"<<QString::number(centerPoint.y());
        m_pixmap=scaledPixmap;
        painter.drawPixmap(centerPoint, m_pixmap);
    }

//    QLabel::paintEvent(event);

}

void ScaledPixelmap::resizeEvent(QResizeEvent *)
{
    int extraWidth=width()-minimumWidth();
    int extraHeight=height()-minimumHeight();
    qDebug()<<"Extra width"<<extraWidth;
    picLabel->move(mapToParent(QCursor::pos()).x()+extraWidth,mapToParent(QCursor::pos()).y()+extraHeight);
}
