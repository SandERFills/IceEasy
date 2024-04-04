#ifndef PORT_H
#define PORT_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QtWidgets>
struct Setting
{

   QString name;
   uint32_t baudRate;
   QSerialPort::DataBits dataBits;
   QSerialPort::StopBits stopBits;
   QSerialPort::FlowControl flowControl;
};

class Port : public QWidget
{
    Q_OBJECT

public:
    Port();
    ~Port();
    void showWidget();


signals:
public slots:
private slots:
    void connectToCom();
    void receiveData();
    void closeCom();

private:
    QByteArray data;
    QWidget* portWidget;
    QSerialPort serialport;
    Setting settingsPort;
    QLabel* portName;
    QComboBox* inPortName;
    QTextEdit* serialOut;
    QVBoxLayout* vBox;
    QHBoxLayout* fistLine;
    QHBoxLayout* secondLine;
    QPushButton* connectButton;
    QPushButton* closeButton;

};

#endif // PORT_H
