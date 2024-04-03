#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDockWidget>
#include <QListWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QMenuBar>
#include <QPushButton>
#include <QImage>
#include <QTransform>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
//    QDockWidget   *contentsWindow = new QDockWidget(tr("Table of Contents"), this);
    QMenu* fileMenu;
    QMenu* deviceMenu;
    QPushButton *statusPB;
    Ui::MainWindow *ui;
    QPixmap image;
    QTransform trans;
    void createFileMenu();
    void createMenu();
    void createStatusBar();
    void createToolBar();
    void createTextEditor();
    void resizeEvent(QResizeEvent*);
private slots:
    void addDock();
    void slotContextMenuPicture(QPoint pos);
    void deviceAdd();
    void showSettings();
protected:
    void contextMenuEvent(QContextMenuEvent*);
};
#endif // MAINWINDOW_H
