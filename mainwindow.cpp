#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerevent.h"

//Qt Style Sheets Examples
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowFlags(Qt::FramelessWindowHint);

    setAttribute(Qt::WA_TranslucentBackground, true);

    setAutoFillBackground(true);

    btnAudio = new QPushButton(this);
    btnBeer = new QPushButton(this);
    btnHDMI = new QPushButton(this);
    btnNetWork = new QPushButton(this);
    btnVGA = new QPushButton(this);
    btnPan = new QPushButton(this);

    btnAudio->setText("音频");
    btnBeer->setText("蜂鸣器");
    btnHDMI->setText("HDMI视频");
    btnVGA->setText("VGA视频");
    btnPan->setText("磁盘容量");
    btnNetWork->setText("网口");

    int y0 = 20;
    int x0 = 300;
    int dy = 70;
    btnAudio->setGeometry(x0,y0,80,40);
    btnPan->setGeometry(x0,y0+dy,80,40);
    btnBeer->setGeometry(x0,y0+dy*2,80,40);
    btnHDMI->setGeometry(x0,y0+dy*3,80,40);
    btnNetWork->setGeometry(x0,y0+dy*4,80,40);
    btnVGA->setGeometry(x0,y0+dy*5,80,40);

    connect(btnAudio,&QPushButton::clicked,this,&MainWindow::on_btnAudio_clicked);
    connect(btnBeer,&QPushButton::clicked,this,&MainWindow::on_btnBeer_clicked);
    connect(btnHDMI,&QPushButton::clicked,this,&MainWindow::on_btnHDMI_clicked);
    connect(btnVGA,&QPushButton::clicked,this,&MainWindow::on_btnVGA_clicked);
    connect(btnPan,&QPushButton::clicked,this,&MainWindow::on_btnPan_clicked);
    connect(btnNetWork,&QPushButton::clicked,this,&MainWindow::on_btnNetWork_clicked);


    //createDialog_timeZoneSetting();
    //createDialog_passwordSetting();
    //createDialog_welcome();
    createVideoWindow(4);
    createDialog_config();
}
bool MainWindow::event(QEvent *event)
{
    //qDebug()<<"event:"<<event->type();
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

void MainWindow::createDialog_config()
{
    QDesktopWidget* pDesktopWidget = QApplication::desktop();
    //获取可用桌面大小
    QRect deskRect = QApplication::desktop()->availableGeometry();
    //获取主屏幕分辨率
    QRect screenRect = QApplication::desktop()->screenGeometry();

    qDebug()<<deskRect.x()<<"    "<<deskRect.y()<<"    "<<deskRect.width()<<"    "<<deskRect.height();

    qDebug()<<screenRect.x()<<"    "<<screenRect.y()<<"    "<<deskRect.width()<<"    "<<deskRect.height();


    if(nvrConfig == nullptr){
        nvrConfig = new NvrConfig(this);
        qDebug()<< nvrConfig->width() << nvrConfig->height();
        nvrConfig->setGeometry((deskRect.width()-nvrConfig->width())/2,(deskRect.height()-nvrConfig->height())/2,nvrConfig->width(),nvrConfig->height());
        nvrConfig->show();
    }
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

    qDebug()<<deskRect.x()<<"    "<<deskRect.y()<<"    "<<deskRect.width()<<"    "<<deskRect.height();

    qDebug()<<screenRect.x()<<"    "<<screenRect.y()<<"    "<<deskRect.width()<<"    "<<deskRect.height();


    if(timeZoneSetting == nullptr){
        timeZoneSetting = new Timezonesetting(this);
        qDebug()<< timeZoneSetting->width() << timeZoneSetting->height();
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

    if(passwordSetting == nullptr){
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

    if(welcome == nullptr){
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


void drawVideoRect(QPainter *paint,int nxn)
{



}

void drawCloudControl(QPainter *paint)
{

}


void MainWindow::on_btnAudio_clicked()
{
    qDebug()<<"音频点击";

}


void MainWindow::on_btnBeer_clicked()
{
    qDebug()<<"音频点击";
}
void MainWindow::on_btnHDMI_clicked()
{
    qDebug()<<"HDMI点击";
}
void MainWindow::on_btnNetWork_clicked()
{
    qDebug()<<"网口点击";
}
void MainWindow::on_btnVGA_clicked()
{
    qDebug()<<"VGA点击";
}
void MainWindow::on_btnPan_clicked()
{
    qDebug()<<"磁盘容量点击";
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标按下";
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标释放";
}
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标双击";
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"鼠标移动";
}
void MainWindow::wheelEvent(QWheelEvent *event)
{
    qDebug()<<"滚轮";
}


