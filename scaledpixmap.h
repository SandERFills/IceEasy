#ifndef SCALEDPIXMAP_H
#define SCALEDPIXMAP_H

#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QPixmap>
#include <QBoxLayout>
#include <QMouseEvent>
QT_FORWARD_DECLARE_CLASS(QPaintEvent)
class ScaledPixmap : public QLabel
{
    Q_OBJECT
public:
    ScaledPixmap();
    void showLabels();
public slots:

    void setScaledPixmap(const QPixmap& pixmap);
    void loadPixmapData(const QString& path);
    void buttMessage()const;
    void displayWidget();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

private:
    QList<QLabel*> lList;
    QLabel *test;
    QPoint offset;


QPixmap hockeyImage=QPixmap("C://Users/MegaAdmin/Documents/EayseOnTheIce/resource/HockeyArena");
private slots:
};

#endif // SCALEDPIXMAP_H
