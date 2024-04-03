#include "settings.h"

Settings::Settings(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle(tr("Настройка COM"));
    QHBoxLayout* hL=new QHBoxLayout;
    hL->addWidget(portName);
    hL->addWidget(portNameIn);
    hL->addWidget(connectDevice);
    setLayout(hL);
}

void Settings::changeCOM()
{

}
