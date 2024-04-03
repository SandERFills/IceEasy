#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
class QrightClickButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QrightClickButton(QWidget *parent = nullptr);
private slots:
    void mousePressEvent(QMouseEvent *e);
signals:
void rightClicked();
public slots:
};

#endif // QRIGHTCLICKBUTTON_H
