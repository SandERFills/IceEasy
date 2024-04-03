#ifndef CENTRALWINDGET_H
#define CENTRALWINDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>
#include <QTransform>
class centralWindget : public QWidget
{
    Q_OBJECT
public:
    explicit centralWindget(QWidget *parent = nullptr);
    void resizeImage(QSize windowSize);
    int width() const;
private slots:
void handleButton();

private:

    QLabel *label;
    QPushButton *pushB1;
    QGridLayout *UIgrid;
    void createInterface();
    void resizeImage(QImage *image, const QSize &newSize);
    QPixmap image;
signals:
};
#endif // CENTRALWINDGET_H
