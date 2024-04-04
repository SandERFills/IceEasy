#include "port.h"
#include "qserialportinfo.h"

Port::Port()

{
    qDebug()<<"Port cpnstructed";
    portWidget=new QWidget();
    vBox=new QVBoxLayout();
    fistLine=new QHBoxLayout();
       portName=new QLabel("Порт: ");
       inPortName=new QComboBox();
       foreach (const QSerialPortInfo &seralPI, QSerialPortInfo::availablePorts()) {
            inPortName->addItem(seralPI.portName());
       }
    fistLine->addWidget(portName);
    fistLine->addWidget(inPortName);
    vBox->addLayout(fistLine);
    secondLine=new QHBoxLayout();
    connectButton=new QPushButton("Connect");
    closeButton=new QPushButton("Close");
    QObject::connect(connectButton,SIGNAL(clicked()),this,SLOT(connectToCom()));
   QObject::connect(closeButton,SIGNAL(clicked()),this,SLOT(closeCom()));
   QObject::connect(&serialport,SIGNAL(readyRead()),this,SLOT(receiveData()));
    secondLine->addWidget(connectButton);
    secondLine->addWidget(closeButton);
    vBox->addLayout(secondLine);
    serialOut=new QTextEdit();
    vBox->addWidget(serialOut);
    portWidget->setLayout(vBox);

}

Port::~Port()
{
    closeCom();
}

void Port::showWidget()
{
portWidget->show();
}
void Port::connectToCom(){
    qDebug()<<"Try to connect";
    serialport.setPortName(inPortName->currentText());
    serialport.setBaudRate(QSerialPort::Baud115200);
    if(!serialport.open(QIODevice::ReadWrite)){
    QMessageBox warnin;
    warnin.setText("Ошибка подключения");
    warnin.exec();
    }

}
void Port::receiveData(){
    QByteArray buff;
    qDebug()<<"Start recive Data";
    buff=(serialport.readAll());
    if(!buff.isEmpty()){
    QString str;
    str+=(buff);
    serialOut->append(str);
    }
    qDebug()<<"T index: "<<buff.indexOf("T");
    qDebug()<<buff;
    buff.clear();
}
void Port::closeCom(){
      qDebug()<<"Try to close";
    serialport.close();
    QMessageBox warn;
    warn.setText("Connection closed");
    warn.exec();
}
