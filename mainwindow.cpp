#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerevent.h"
#include <QIcon>
#include <QWidgetAction>
#include <QHBoxLayout>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAutoFillBackground(true);


    listVideoW.clear();
    //createDialog_timeZoneSetting();
    //createDialog_passwordSetting();
    //createDialog_welcome();
    createVideoWindow(4);
    currentShowType = MASTERPREVIEW;
    //createDialog_config();
    // createReplayWindow();


}

bool MainWindow::event(QEvent *event)
{

    //  qDebug()<<"dsadsa:"<<event->type();
    if (event->type() == CustomerEvent::eventType())
    {
        CustomerEvent *customerEvent = dynamic_cast<CustomerEvent*>(event);
        qDebug() <<"MainWindow:"<< customerEvent->getValueString();
        return true;
    }else if (event->type() == QEvent::MouseButtonPress) {
        qDebug() <<"MainWindow:"<< event->type();
    }
    return QWidget::event(event);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createReplayWindow()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    if(replayWindow == NULL){
        replayWindow = new ReplayWindow(this);
        replayWindow->setGeometry(0,0,deskRect.width(),deskRect.height());
        replayWindow->init();

        connect(nvrConfig,SIGNAL(signal_switchWindow(WindowType type)),this,SLOT(slot_switchWindow(WindowType type)));

    }
    replayWindow->show();

}

void MainWindow::createDialog_config()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    if(nvrConfig == NULL){
        nvrConfig = new NvrConfig(this);
        nvrConfig->setGeometry((deskRect.width()-nvrConfig->width())/2,(deskRect.height()-nvrConfig->height())/2,nvrConfig->width(),nvrConfig->height());

        connect(nvrConfig,SIGNAL(signal_switchWindow(WindowType )),this,SLOT(slot_switchWindow(WindowType )));
    }
    nvrConfig->show();
}

void MainWindow::createVideoWindow(int n)
{

    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    int widthPerRect = (deskRect.width() - rectSpace *(videoN-1))/videoN;
    int heightPerRect = (deskRect.height() - rectSpace *(videoN-1))/videoN;
    for (int i=0;i<videoN;i++) {

        for(int j=0;j<videoN;j++){//横向添加
            VideoWindow *videoWindow = new VideoWindow(this,widthPerRect,heightPerRect);

            videoWindow->setGeometry((widthPerRect+rectSpace)*j ,(heightPerRect+rectSpace)*i,widthPerRect,heightPerRect);


            listVideoW.append(videoWindow);
        }
    }
}
void MainWindow::createDialog_timeZoneSetting()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();


    if(timeZoneSetting == NULL){
        timeZoneSetting = new Timezonesetting(this);

        timeZoneSetting->setGeometry((deskRect.width()-timeZoneSetting->width())/2,(deskRect.height()-timeZoneSetting->height())/2,timeZoneSetting->width(),timeZoneSetting->height());
        timeZoneSetting->show();
    }
}
void MainWindow::createDialog_passwordSetting()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    if(passwordSetting == NULL){
        passwordSetting = new PasswordSetting(this);
        passwordSetting->setGeometry((deskRect.width()-passwordSetting->width())/2,(deskRect.height()-passwordSetting->height())/2,passwordSetting->width(),passwordSetting->height());
        passwordSetting->show();
    }
}

void MainWindow::createDialog_welcome()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    if(welcome == NULL){
        welcome = new Welcome(this);
        welcome->setGeometry((deskRect.width()-welcome->width())/2,(deskRect.height()-welcome->height())/2,welcome->width(),welcome->height());
        welcome->show();
    }
}


void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter pt(this);

    QColor c(Qt::gray);
    c.setAlpha(0);
    pt.fillRect(rect(), c);
    QPen pen(QColor("#252525"),rectSpace);

    pen.setBrush(QBrush(QColor("#252525")));
    pt.setPen(pen);


    int widthPerRect = (rect().width() - rectSpace *(videoN-1))/videoN;
    int heightPerRect = (rect().height() - rectSpace *(videoN-1))/videoN;

    for(int i = 0;i<videoN-1;i++){//画线
        pt.drawLine(widthPerRect*(i+1) + rectSpace*i,0,widthPerRect*(i+1) + rectSpace*i,rect().height());//竖线
        pt.drawLine(0,heightPerRect*(i+1) + rectSpace*i,rect().width(),heightPerRect*(i+1) + rectSpace*i);//横线
    }
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {

    }
    // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton)
    {
        qDebug()<<"鼠标右键按下";
        popMenu();
    }
}
void MainWindow::popMenu()
{


    //初始化菜单
    if(rightMouseMenu == NULL){
        rightMouseMenu = new QMenu(this);


        QWidgetAction *buttonActionCloudControl = new QWidgetAction(this);
        QWidgetAction *buttonActionReplay = new QWidgetAction(this);
        QWidgetAction *buttonActionDeviceSet = new QWidgetAction(this);
        QWidgetAction *buttonActionSystemSet = new QWidgetAction(this);


        QPushButton *pbtnCloudControl =  createSelfBtn(tr("PTZ Control"),":/images/menu_cloudcontrol.png");
        buttonActionCloudControl->setDefaultWidget(pbtnCloudControl);

        QPushButton *pbtnReplay =  createSelfBtn(tr("Video Replay"),":/images/menu_replay.png");
        buttonActionReplay->setDefaultWidget(pbtnReplay);

        QPushButton *pbtnDeviceSet =  createSelfBtn(tr("Device Setting"),":/images/menu_deviceManager.png");
        buttonActionDeviceSet->setDefaultWidget(pbtnDeviceSet);

        QPushButton *pbtnSystemSet =  createSelfBtn(tr("System Setting"),":/images/menu_systemmanager.png");
        buttonActionSystemSet->setDefaultWidget(pbtnSystemSet);

        //动作添加到菜单
        rightMouseMenu->addAction(buttonActionCloudControl);
        rightMouseMenu->addAction(buttonActionReplay);
        rightMouseMenu->addAction(buttonActionDeviceSet);
        rightMouseMenu->addAction(buttonActionSystemSet);

        //给动作设置信号槽
        connect( pbtnCloudControl, SIGNAL(clicked()),this,SLOT(slot_menuSelectCloudControl()));
        connect( pbtnReplay, SIGNAL(clicked()),this,SLOT(slot_menuSelectReplay()));
        connect( pbtnDeviceSet, SIGNAL(clicked()),this,SLOT(slot_menuSelectDeviceSet()));
        connect( pbtnSystemSet,SIGNAL(clicked()), this,SLOT(slot_menuSelectSystemSet()));
    }




    rightMouseMenu->exec(QCursor::pos());
}

void MainWindow::slot_menuSelectCloudControl()
{rightMouseMenu->close();}

void MainWindow::slot_menuSelectReplay()
{
    rightMouseMenu->close();
    slot_switchWindow(REPLAYVIDEO);
}
void MainWindow::slot_menuSelectDeviceSet()
{
    rightMouseMenu->close();
    slot_switchWindow(DEVICESET);
}
void MainWindow::slot_menuSelectSystemSet()
{rightMouseMenu->close();
    slot_switchWindow(SYSTEMSET);
}
void MainWindow::showMasterVideo(bool isShow)
{
    if(listVideoW.size()<=0)
        createVideoWindow(4);

    if(isShow){

        for (int i=0;i<listVideoW.size();i++)
            listVideoW.at(i)->show();

    }else {

        for (int i=0;i<listVideoW.size();i++)
            listVideoW.at(i)->hide();
    }

}
void MainWindow::slot_switchWindow(WindowType type)
{


    //隐藏当前的窗口
    switch (currentShowType)
    {
    case MASTERPREVIEW:
        if(type == REPLAYVIDEO)
            showMasterVideo(false);
        break;
    case REPLAYVIDEO:
        if(type == MASTERPREVIEW)
            replayWindow->hide();
        break;
    }

    //显示切换的窗口
    switch (type) {
    case MASTERPREVIEW:
        showMasterVideo(true);
        currentShowType = type;
        break;
    case REPLAYVIDEO:
        createReplayWindow();
        currentShowType = type;
        break;
    case SYSTEMSET:

        if(nvrConfig == NULL)
            createDialog_config();
        nvrConfig->showSystemSet();

        break;
    case DEVICESET:

        if(nvrConfig == NULL)
            createDialog_config();
        nvrConfig->showDeviceSet();
        break;

    default:
        return;
    }



}

QPushButton *MainWindow::createSelfBtn(QString btnTxt,QString res)
{
    const QSize btnSize(236,42);
    QPushButton *btn = new QPushButton();

    btn ->setFixedSize(btnSize);
    btn ->setStyleSheet("QPushButton{background-color: #171717;border:none}"
                        "QPushButton:pressed{background-color: #476BFD;}");
    QLabel* label = new QLabel();
    QLabel* label2 = new QLabel();
    label2->setFixedSize(QSize(20,20));
    QString sty = "border-image:url("+res+");background-color: #00ffffff;";
    label->setStyleSheet("background-color: #00ffffff;font-size: 16px;font-family:Microsoft Yahei;color:white;font:#ffffff");
    label2 ->setStyleSheet(sty);

    label->setText(btnTxt);
    QHBoxLayout* myLayout = new QHBoxLayout();
    myLayout->addSpacing(20);
    myLayout->addWidget(label2);
    myLayout->addSpacing(10);
    myLayout->addWidget(label);
    myLayout->addStretch();
    btn->setLayout(myLayout);

    return btn;
}

