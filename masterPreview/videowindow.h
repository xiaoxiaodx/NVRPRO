#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QWidget>

enum MasterControl{

    PTZ_UP = 0,
    PTZ_DOWN,
    PTZ_LEFT,
    PTZ_RIGHT,
    REPLAY,
    SETHOME,
    RECORDVIDEO
};
namespace Ui {
class VideoWindow;
}

class VideoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = NULL,int mW = 0,int mH = 0 ,int identify = -1);
    ~VideoWindow();


    int getIdentify();
    void showControl();
    void adjustWsize(int w,int h);

    void hideControl();
    void haveVideo();
    void noVideo();
     bool isMax = false;
     bool isSelect = false;

signals:
    void signal_selectVideo(int identify);
    void signal_dClickVideo(int identify,bool isMax);
    void signal_masterControl(int identify,MasterControl type);
private slots:
    void on_pushButton_cloudControl_right_clicked();

    void on_pushButton_cloudControl_left_clicked();

    void on_pushButton_cloudControl_up_clicked();

    void on_pushButton_cloudControl_down_clicked();

    void on_pushButton_setHome_clicked();

    void on_pushButton_replay_clicked();

    void on_pushButton_video_swith_clicked();

private:

    Ui::VideoWindow *ui;
    void setControlPostion();

    int mWidth = 0;//提前获取的宽高保存在这
    int mHeight = 0;

    bool mouseIsInsideInterface = false;
    bool event(QEvent *event);
    int mIdentify;



};

#endif // VIDEOWINDOW_H
