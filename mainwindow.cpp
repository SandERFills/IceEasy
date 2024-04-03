#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "scaledpixelmap.h"
#include <QLabel>
#include "port.h"
#include "settings.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Catch Ass on the ice"));
    createFileMenu();
    QWidget* centralWid=new QWidget(this);
    QHBoxLayout* Hbox=new QHBoxLayout();
    image.load("D://Qt/untitled5/resourse/hockeyArena.jpg");
    if(image.isNull()){
        qDebug("picture dont loaded");
        }
    trans.rotate(90);
    image=image.transformed(trans);
    ScaledPixelmap* picLabel= new ScaledPixelmap();
    picLabel->setScaledPixmap((image));
    picLabel->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(picLabel,&ScaledPixelmap::customContextMenuRequested,
            this,&MainWindow::slotContextMenuPicture);
    Hbox->addWidget(picLabel);
    centralWid->setLayout(Hbox);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createFileMenu()
{
   fileMenu=menuBar()->addMenu("Файл");
   QAction* setting=new QAction(tr("Настройки"));
   connect(setting,SIGNAL(triggered(bool)),this,SLOT(showSettings()));
   fileMenu->addAction(setting);

   deviceMenu=menuBar()->addMenu("Настройка устроств");
   deviceMenu->addAction("Назначить устройства");
   deviceMenu->addAction("Настройка порта");
}

void MainWindow::createMenu()
{
QAction *hockeyArena=new QAction("Хоккей",this);
QAction *curlingArena=new QAction("Кёрлинг",this);
QMenu *arenaMenu=menuBar()->addMenu("Выберете арену");
arenaMenu->addAction(curlingArena);
arenaMenu->addAction(hockeyArena);
QMenu *fileMenu=menuBar()->addMenu(tr("File"));


}

void MainWindow::createStatusBar()
{


}

void MainWindow::createToolBar()
{
    QToolBar *toolBar=new QToolBar("Выберите арену",this);
    toolBar->addAction("A");
    toolBar->addAction("B");
    addToolBar(toolBar);
}

void MainWindow::createTextEditor()
{

}

void MainWindow::resizeEvent(QResizeEvent *e)
{

}

void MainWindow::addDock()
{
    QDockWidget   *contentsWindow = new QDockWidget(tr("Table of Contents"), this);
    contentsWindow->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QListWidget *headingList = new QListWidget(contentsWindow);
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText("itemText");
    headingList->insertItem(0, newItem);

    contentsWindow->setWidget(headingList);
    setCorner(Qt::TopLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::TopRightCorner, Qt::RightDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea,contentsWindow);
}

void MainWindow::slotContextMenuPicture(QPoint pos)
{
    qDebug()<<"Right click on picture";
    QMenu* menu=new QMenu(this);
    QAction* device1=new QAction("Device2",this);

    menu->addAction("Device 1");
    menu->addAction(device1);
    connect(device1, SIGNAL(triggered()), this, SLOT(deviceAdd()));
    menu->exec(QCursor::pos());
    qDebug()<<QCursor::pos();

}

void MainWindow::deviceAdd()
{
qDebug()<<"Вызов девайса";
QLabel* deviceLabel=new QLabel(this);
deviceLabel->setText("Keks Text");
deviceLabel->move(QCursor::pos());
deviceLabel->show();
}

void MainWindow::showSettings()
{
    Port* serialPort=new Port();

}

void MainWindow::contextMenuEvent(QContextMenuEvent *)
{

}

