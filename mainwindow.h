#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QDockWidget"
#include "centralwidget.h"
#include <QMessageBox>
#include <QGroupBox>
#include <QLayout>
#include <QRadioButton>
#include <Qlayout>
#include <ui_mainwindow.h>
#include <QTextEdit>
#include <QMainWindow>
#include "centralwidget.h"
#include <QListWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QDialogButtonBox>
#include <QScrollArea>
#include <QFormLayout>
#include <QMouseEvent>
#include "device.h"
#include "scaledpixmap.h"
#include "port.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
      // Функция отклика контекстного меню
    void slotContextMenuPicture(QPoint pos);
    void slotContextMenuButton(QPoint pos);
    void slotFshowDevicePanel();

    void device1Print();
private:
    enum { NumGridRows = 3, NumButtons = 4 };

    Ui::MainWindow *ui;
//    centralW *cenW;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QPushButton *buttons[NumButtons];
    QDialogButtonBox *buttonBox;
    QPixmap hockeyImage=QPixmap("C://Users/MegaAdmin/Documents/EayseOnTheIce/resource/HockeyArena");
    ScaledPixmap *hockeyLabel;
    QMenu *fileMenu;
    QMenu* deviceMenu;
    QAction *exitAction;
    QHBoxLayout* centralHLyaout;
    void CentralWidgetUI();
    void DockeWidgetsUI();
    void StatusBarUI();
    void ToolsCreateUI();
    void FileMenu();
    QToolBar* newPanel;
    void MenuUI();
    void makeItem(QListWidget* lstWgt);
    void onBtnClicked();
    void createMenu();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void createFormGroupBox();
    void createRightClickMenu(QMouseEvent* ,QMenu*);
    QPushButton* testB;

    QAction* newAct=new QAction(tr("&New"),this);
    Port* serialPort;
    QSize oldSize;
protected:
//    void mousePressEvent(QMouseEvent* );
    void paintEvent(QPaintEvent *);
    void contextMenuEvent(QContextMenuEvent*);
    void resizeEvent(QResizeEvent*);
};
#endif // MAINWINDOW_H
