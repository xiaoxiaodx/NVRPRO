#include "videowindow.h"
#include "ui_videowindow.h"
#include <QDebug>
VideoWindow::VideoWindow(QWidget *parent,int mW,int mH) :
    QWidget(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    mWidth = mW;
    mHeight = mH;
    setControlPostion();
}

VideoWindow::~VideoWindow()
{
    delete ui;
}


void VideoWindow::setControlPostion()
{

    int cloudControllW = 160;
    int cloudControllH = 160;


    int videoLossW = 283;
    int videoLossH = 30;

    int motionDetectionW = 40;
    int motionDetectionH = 40;

//    int setHomeW = 32;
//    int setHomeH = 32;

//    int videoReplayW = 32;
//    int videoReplayH = 32;

//    int videoSwitchW = 32;
//    int videoSwitchH = 32;

    int commonBtnW = 32;
    int commonBtnH = 32;

    qDebug()<<"W W "<<this->width() << "    "<<mWidth;
    int thisW = mWidth;
    int thisH = mHeight;

    int ipcIdentifyW = 92;
    int ipcIdentifyH = 18;

    int recordStateW = 57;
    int recordStateH = 24;


    ui->widget_cloudControl->setGeometry(10,thisH-cloudControllH-10,cloudControllW,cloudControllH);

    ui->label_videoLoss->setGeometry((thisW - videoLossW)/2,(thisH - videoLossH)/2,videoLossW,videoLossH);

    ui->label_ipc_identify->setGeometry(20,20,ipcIdentifyW,ipcIdentifyH);
    ui->label_recordState->setGeometry(20 + 30 + ipcIdentifyW,ipcIdentifyH,recordStateW,recordStateH);
    ui->pushButton_motionDetection->setGeometry(thisW-20-motionDetectionW,52,motionDetectionW,motionDetectionH);

    qDebug()<<" ui->widget_cloudControl "<<ui->widget_cloudControl->x()<<"  "<<ui->widget_cloudControl->y();

    //从右边第一个按钮开始为准，另外2个按钮以他为基准
    int btnY = thisH - 12 - commonBtnH;
    int firstBtnX = thisW - 40 - commonBtnW;
    ui->pushButton_video_swith->setGeometry(firstBtnX,btnY,commonBtnW,commonBtnH);
    ui->pushButton_replay->setGeometry(firstBtnX-42-commonBtnW,btnY,commonBtnW,commonBtnH);
    ui->pushButton_setHome->setGeometry(firstBtnX-116-commonBtnW,btnY,commonBtnW,commonBtnH);



}
