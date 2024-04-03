#include "mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    Port serialServ=Port();

    return a.exec();
}

