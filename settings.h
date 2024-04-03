#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
class Settings : public QWidget
{
    Q_OBJECT
private:
       QLabel* portName=new QLabel(tr("Порт"),this);
        QLineEdit* portNameIn=new QLineEdit(this);
        QPushButton* connectDevice=new QPushButton(tr("Подключиться к устройству"),this);
public:
    explicit Settings(QWidget *parent = nullptr);

signals:
    void changedCOM();
private slots:
    void changeCOM();

};

#endif // SETTINGS_H
