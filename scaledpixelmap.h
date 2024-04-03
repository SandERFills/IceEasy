#ifndef SCALEDPIXELMAP_H
#define SCALEDPIXELMAP_H

#include <QLabel>
#include <QObject>
#include <QtGui/QPixmap>
#include <QMouseEvent>
#include <QApplication>
QT_FORWARD_DECLARE_CLASS(QPaintEvent);

class ScaledPixelmap : public QLabel
{
    Q_OBJECT
public:
    ScaledPixelmap();

public slots:
    void setScaledPixmap(const QPixmap& pixmap);
    void loadPixmapData(const QString& path);

private slots:
    void mousePressEvent(QMouseEvent*);
private:
    QPixmap m_pixmap;
    QSize   m_originalSize;
    QLabel* picLabel=new QLabel("Test",this);
protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
};

#endif // SCALEDPIXELMAP_H
