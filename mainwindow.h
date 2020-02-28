#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>

#include "timezonesetting.h"
#include "passwordsetting.h"
#include "welcome.h"
#include "masterPreview/videowindow.h"
#include "nvrConfig/nvrconfig.h"
#include "videoReplay/replaywindow.h"
#include "virtualkeyboard.h"
#include <QMouseEvent>
#include "inputeditkeyeventfilter.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = NULL);
    ~MainWindow();
static VirtualKeyboard *virtualKeyboard;
static InputEditKeyEventFilter *EditKeyEventFilter;

public slots:
    void slot_switchWindow(WindowType type);
    void slot_menuSelectCloudControl();
    void slot_menuSelectReplay();
    void slot_menuSelectDeviceSet();
    void slot_menuSelectSystemSet();

    //主预览
    void slot_selectVideo(int);
    void slot_masterControl(int ide,MasterControl type);
    //密码设置
    void slot_passwordSetting(QString,QString);
    //时区
    void slot_timezoneStr(QString);
    //登录
    void slot_loginStr(QString);
protected:
    void paintEvent(QPaintEvent*);


    void mousePressEvent(QMouseEvent *event);

    bool event(QEvent *event);


private:
    Ui::MainWindow *ui;

    void popMenu();

    void createDialog_timeZoneSetting();
    void createDialog_passwordSetting();
    void createDialog_welcome();
    void createVideoWindow(int n);
    void createDialog_config();
    void createReplayWindow();
    void createSingletonKeyBorad();
    void createSingletonEditKeyEventFilter();

    void showMasterVideo(bool isShow);

   // void switchWindow(WindowType type);
//    void drawVideoRect(QPainter *paint,int nxn);
//    void drawCloudControl(QPainter *paint);

    QPushButton *createSelfBtn(QString str,QString res);

    int const rectSpace = 2;//分屏的时候，相邻矩形的边距
    int const videoN = 2;//几乘几的视频显示

    QMenu *rightMouseMenu = NULL;

    QList<VideoWindow*> listVideoW;
    ReplayWindow *replayWindow = NULL;
    NvrConfig *nvrConfig = NULL;
    Timezonesetting *timeZoneSetting = NULL;
    PasswordSetting *passwordSetting = NULL;
    Welcome *welcome = NULL;

    WindowType currentMainWindowShowType;



};

#endif // MAINWINDOW_H
