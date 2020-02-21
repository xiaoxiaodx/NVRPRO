#include "videowindow.h"
#include "ui_videowindow.h"
#include <QDebug>
#include "customerevent.h"
VideoWindow::VideoWindow(QWidget *parent,int mW,int mH) :
    QWidget(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    mWidth = mW;
    mHeight = mH;


    QPushButton *button = new QPushButton(this);
    button->setText("测试自定义事件");
    // 建立连接, 发送信号
    QObject::connect(button, &QPushButton::clicked, [=](void)->void{
        // 使用PostEvent方式发送
        CustomerEvent *customerEvent = new CustomerEvent("PostCustomerEvent");
        QCoreApplication::postEvent(this->parent(), customerEvent);

        // 使用SendEvent方式发送
        CustomerEvent *sendCustomerEvent = new CustomerEvent("SendCustomerEvent");
        bool result = QCoreApplication::sendEvent(this, sendCustomerEvent);
        qDebug() << "The Dispose Result Is " << result;
        delete sendCustomerEvent;
    });

    setControlPostion();
}

VideoWindow::~VideoWindow()
{
    delete ui;
}

bool VideoWindow::event(QEvent *event)
{
    if (event->type() == CustomerEvent::eventType())
    {
        CustomerEvent *customerEvent = dynamic_cast<CustomerEvent*>(event);
        qDebug() <<"VideoWindow:"<< customerEvent->getValueString();
        return true;
    }else if (event->type() == QEvent::MouseButtonPress) {
        qDebug() <<"VideoWindow:"<< event->type();
    }

    return QWidget::event(event);
}

void VideoWindow::setControlPostion()
{
    int cloudControllW = 160;
    int cloudControllH = 160;

    int videoLossW = 283;
    int videoLossH = 30;

    int motionDetectionW = 40;
    int motionDetectionH = 40;

    int commonBtnW = 32;
    int commonBtnH = 32;

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

    //从右边第一个按钮开始为准，另外2个按钮以他为基准
    int btnY = thisH - 12 - commonBtnH;
    int firstBtnX = thisW - 40 - commonBtnW;
    ui->pushButton_video_swith->setGeometry(firstBtnX,btnY,commonBtnW,commonBtnH);
    ui->pushButton_replay->setGeometry(firstBtnX-42-commonBtnW,btnY,commonBtnW,commonBtnH);
    ui->pushButton_setHome->setGeometry(firstBtnX-116-commonBtnW,btnY,commonBtnW,commonBtnH);
}
