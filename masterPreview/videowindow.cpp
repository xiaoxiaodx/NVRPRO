#include "videowindow.h"
#include "ui_videowindow.h"
#include <QDebug>
#include "customerevent.h"
VideoWindow::VideoWindow(QWidget *parent,int mW,int mH,int identify) :
    QWidget(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    mWidth = mW;
    mHeight = mH;
    mIdentify = identify;

//    QPushButton *button = new QPushButton(this);
//    button->setText("测试自定义事件");
//    // 建立连接, 发送信号
//    QObject::connect(button, &QPushButton::clicked, [=](void)->void{
//        // 使用PostEvent方式发送
//        CustomerEvent *customerEvent = new CustomerEvent("PostCustomerEvent");
//        QCoreApplication::postEvent(this->parent(), customerEvent);

//        // 使用SendEvent方式发送
//        CustomerEvent *sendCustomerEvent = new CustomerEvent("SendCustomerEvent");
//        bool result = QCoreApplication::sendEvent(this, sendCustomerEvent);
//        qDebug() << "The Dispose Result Is " << result;
//        delete sendCustomerEvent;
//    });

    setControlPostion();
    hideControl();
}

VideoWindow::~VideoWindow()
{
    delete ui;
}

bool VideoWindow::event(QEvent *event)
{

    if(event->type() == QEvent::MouseButtonPress){

        emit signal_selectVideo(mIdentify);
    }

    return QWidget::event(event);
}

void VideoWindow::haveVideo()
{
    ui->label_videoLoss->setVisible(false);
}

void VideoWindow::noVideo()
{
    ui->label_videoLoss->setVisible(true);
}

void VideoWindow::showControl()
{
    ui->frame->setStyleSheet("#frame{border:2px solid #476BFD}");
    ui->widget_cloudControl->setVisible(true);
    ui->pushButton_setHome->setVisible(true);
    ui->pushButton_replay->setVisible(true);
    ui->pushButton_video_swith->setVisible(true);

}
void VideoWindow::hideControl()
{

    ui->frame->setStyleSheet("#frame{border:0px solid #476BFD}");
    ui->widget_cloudControl->setVisible(false);
    ui->pushButton_setHome->setVisible(false);
    ui->pushButton_replay->setVisible(false);
    ui->pushButton_video_swith->setVisible(false);
}

int VideoWindow::getIdentify()
{
    return mIdentify;
}
void VideoWindow::setControlPostion()
{
    int cloudControllW = 160;
    int cloudControllH = 160;

    int videoLossW = 283;
    int videoLossH = 30;

    int motionDetectionW = 24;
    int motionDetectionH = 24;

    int commonBtnW = 32;
    int commonBtnH = 32;

    int thisW = mWidth;
    int thisH = mHeight;

    int ipcIdentifyW = 92;
    int ipcIdentifyH = 18;

    int recordStateW = 57;
    int recordStateH = 24;


    ui->frame->setGeometry(0,0,mWidth,mHeight);

    ui->widget_cloudControl->setGeometry(10,thisH-cloudControllH-10,cloudControllW,cloudControllH);

    ui->label_videoLoss->setGeometry((thisW - videoLossW)/2,(thisH - videoLossH)/2,videoLossW,videoLossH);

    ui->label_ipc_identify->setGeometry(20,20,ipcIdentifyW,ipcIdentifyH);
    ui->label_recordState->setGeometry(20 + 30 + ipcIdentifyW,ipcIdentifyH,recordStateW,recordStateH);
    ui->pushButton_motionDetection->setGeometry(thisW-20-motionDetectionW,52,motionDetectionW,motionDetectionH);

    //从右边第一个按钮开始为准，另外2个按钮以他为基准
    int btnY = thisH - 12 - commonBtnH;
    int firstBtnX = thisW - 40 - commonBtnW;
    ui->pushButton_video_swith->setGeometry(firstBtnX,btnY,commonBtnW,commonBtnH);
    ui->pushButton_replay->setGeometry(firstBtnX-42-commonBtnW,btnY,commonBtnW,commonBtnH);
    ui->pushButton_setHome->setGeometry(firstBtnX-116-commonBtnW,btnY,commonBtnW,commonBtnH);
}

void VideoWindow::on_pushButton_cloudControl_right_clicked()
{
    emit signal_masterControl(mIdentify,PTZ_RIGHT);
}

void VideoWindow::on_pushButton_cloudControl_left_clicked()
{

    emit signal_masterControl(mIdentify,PTZ_LEFT);
}

void VideoWindow::on_pushButton_cloudControl_up_clicked()
{
    emit signal_masterControl(mIdentify,PTZ_UP);
}

void VideoWindow::on_pushButton_cloudControl_down_clicked()
{
    emit signal_masterControl(mIdentify,PTZ_DOWN);
}

void VideoWindow::on_pushButton_setHome_clicked()
{
    emit signal_masterControl(mIdentify,SETHOME);
}

void VideoWindow::on_pushButton_replay_clicked()
{
    emit signal_masterControl(mIdentify,REPLAY);
}

void VideoWindow::on_pushButton_video_swith_clicked()
{
    emit signal_masterControl(mIdentify,RECORDVIDEO);
}
