#include "mainwindow.h"

#include <QFormLayout>
#include "device.h"
#include <QtSerialPort/QSerialPort>
#include "devicepanel.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    FileMenu();

    QWidget* centWid=new QWidget(this);
    centralHLyaout=new QHBoxLayout();
    if(hockeyImage.isNull()){
        qDebug("Изображение не загружено");
    }
    QTransform transImg;
    transImg.rotate(90);
    hockeyImage= hockeyImage.transformed(transImg);
    hockeyLabel=new ScaledPixmap();
    hockeyLabel->setScaledPixmap(hockeyImage);
    hockeyLabel->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(hockeyLabel,&ScaledPixmap::customContextMenuRequested,
            this,&MainWindow::slotContextMenuPicture);
    centralHLyaout->addWidget(hockeyLabel);
    centWid->setLayout(centralHLyaout);
    setCentralWidget(centWid);
    serialPort=new Port();
//    testB->move();
    testB=new QPushButton("TEST",this);
    testB->show();
oldSize=size();

}

MainWindow::~MainWindow()
{
}

void MainWindow::slotContextMenuButton(QPoint pos)
{
    qDebug()<<" Right context button";
}

void MainWindow::slotFshowDevicePanel()
{
// devicePanel *panel=new devicePanel();
// panel->FaddNewDevice();
// panel->show();
    serialPort->showWidget();
}

void MainWindow::device1Print()
{
    QGroupBox *device1=new QGroupBox("Device1",hockeyLabel);
    QVBoxLayout *vbox=new QVBoxLayout;
    vbox->addStretch(1);
    QLabel *lbName=new QLabel("Keeek1",device1);
    QLabel *lbNm=new QLabel("Keeek2",device1);
    vbox->addWidget(lbName);
    vbox->addWidget(lbNm);
    device1->setLayout(vbox);
    device1->show();
    device1->move(mapFromGlobal(QCursor::pos()));
    qDebug()<<"BoxG x/y"<<size().width()-hockeyLabel->size().width()<<"/"<<size().height()-hockeyLabel->size().height();
////    dev1.move((QCursor::pos()));
//    dev1.show();
    qDebug()<<("device 1");
}

void MainWindow::slotContextMenuPicture(QPoint pos)
{
    qDebug()<<" Right context picture";
   QMenu* menu =new QMenu(this);

    QAction* device1=menu->addAction("sd");
    QAction* device2=menu->addAction("sd2");

    qDebug()<<"Right click";
    connect(device1,SIGNAL(triggered()),this,SLOT(device1Print()));
    connect(device2,SIGNAL(triggered()),this,SLOT(device1Print()));
    menu->exec(QCursor::pos());
    qDebug()<<QCursor::pos()<<"/"<<mapFromGlobal(QCursor::pos());

}


void MainWindow::CentralWidgetUI()
{

}

void MainWindow::DockeWidgetsUI()
{

 QDockWidget *dock = new QDockWidget(tr("Customers"), this);
     dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
     //QListWidget*  customerList = new QListWidget(dock);
     // container QWidget to put QVBoxLayout containing QLabel and QTextEdit
//      QWidget *widDockWid = new QWidget(dock);
      QVBoxLayout *layoutDockWid = new QVBoxLayout();
      QLabel *labelTemp = new QLabel(tr("Температура"));
      QLabel *labelMac = new QLabel(tr("MAC адрес"));
      layoutDockWid->addWidget(labelTemp);
      layoutDockWid->addWidget(labelMac);

//      widDockWid->setLayout(layoutDockWid);
//      dock->setWidget(widDockWid);
//      widDockWid->setVisible(true);

        layoutDockWid->setAlignment(Qt::AlignTop);
      horizontalGroupBox->setLayout(layoutDockWid);
      dock->setWidget(horizontalGroupBox);
    addDockWidget(Qt::RightDockWidgetArea, dock);



}

void MainWindow::StatusBarUI()
{

}

void MainWindow::ToolsCreateUI()
{
newPanel=addToolBar(tr("New pane"));

}

void MainWindow::FileMenu()
{
    QAction *Afile=new QAction("Файл",this);
    QAction *Asetting=new QAction("Настройки",this);
    fileMenu=menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(Afile);
    fileMenu->addSeparator();
    fileMenu->addAction(Asetting);
    deviceMenu=menuBar()->addMenu(tr("&Панель девайсов"));
    QAction *devicePanel=new QAction("Панель девайсов",this);
    deviceMenu->addAction(devicePanel);
    connect(devicePanel,SIGNAL(triggered()),this,SLOT(slotFshowDevicePanel()));


}

void MainWindow::MenuUI()
{

}

void MainWindow::makeItem(QListWidget *lstWgt)
{
}

void MainWindow::onBtnClicked()
{

}

void MainWindow::createRightClickMenu(QMouseEvent* eventMouse, QMenu *menu)
{
    if(Qt::RightButton==eventMouse->button()){
        menu =new QMenu(this);
        menu->addAction("sd");
        qDebug()<<"Right click";
        menu->exec(eventMouse->globalPos());
    }
    eventMouse->accept();

}

void MainWindow::paintEvent(QPaintEvent * const event)
{
    qDebug()<<"Размер окна"<<size();
}


//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    createRightClickMenu(event,fileMenu);

//}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{

}

void MainWindow::resizeEvent(QResizeEvent *event_resize)
{
    qDebug()<<"Called resize event";
    qDebug()<<"New size: "<<size();
    qDebug()<<"Old size: "<<oldSize;
    qDebug()<<"Devers: "<<oldSize-size();
    testB->move(oldSize.width()-size().width()+100,oldSize.height()-size().height()+100);
}

