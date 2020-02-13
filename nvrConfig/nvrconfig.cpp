#include "nvrconfig.h"
#include "ui_nvrconfig.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QDebug>
NvrConfig::NvrConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NvrConfig)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    this->setModal(true);
    setControlPostion();
    setMenuItem();

    initStackedWidget();
}

void NvrConfig::initStackedWidget()
{

    if(deviceSetting == nullptr){

        deviceSetting = new DeviceSetting(this);
        //deviceSetting->resize(ui->stackedWidget->width(),ui->stackedWidget->height());
        qDebug()<<"initStackedWidget "<<ui->stackedWidget->width()<<"    "<<ui->stackedWidget->height();

        ui->stackedWidget->addWidget(deviceSetting);

    }

    if(systemManager == nullptr){
        systemManager = new SystemManager(this);
        ui->stackedWidget->addWidget(systemManager);

    }
}

void NvrConfig::setMenuItem()
{
    QPushButton *btnMasterPreview = createSelfBtn("Master Preview",":/images/masterPreview.png");
    QPushButton *btnReplay= createSelfBtn("Video Replay",":/images/video_replay.png");
    QPushButton *btnDeviceSetting= createSelfBtn("Device Setting",":/images/device_setting.png");
    QPushButton *btnSystemManagement= createSelfBtn("System Management",":/images/system_manager.png");

    /*单选菜单效果*/
    QButtonGroup *buttonGround = new QButtonGroup(this);
    buttonGround->addButton(btnMasterPreview);
    buttonGround->addButton(btnReplay);
    buttonGround->addButton(btnDeviceSetting);
    buttonGround->addButton(btnSystemManagement);
    buttonGround->setExclusive(true);

    connect(btnDeviceSetting,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentWidget(deviceSetting);
    });

    connect(btnSystemManagement,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentWidget(systemManager);
    });
    /*容器包含*/
    QVBoxLayout *menuLayout = new QVBoxLayout();
    menuLayout->setMargin(0);
    menuLayout->setSpacing(5);
    menuLayout->addSpacing(5);
    menuLayout->addWidget(btnMasterPreview);
    menuLayout->addWidget(btnReplay);
    menuLayout->addWidget(btnDeviceSetting);
    menuLayout->addWidget(btnSystemManagement);
    menuLayout->addStretch();

    ui->widget_menu->setLayout(menuLayout);
}


QPushButton * NvrConfig::createSelfBtn(QString btnTxt,QString res)
{
    const QSize btnSize(218,36);
    QPushButton *btn = new QPushButton();

    btn ->setCheckable(true);
    btn ->setFixedSize(btnSize);
    btn ->setStyleSheet("QPushButton{background-color: #FFFFFF;border:none}"
                        "QPushButton:checked{background-color: #F1F4FF;}");
    QLabel* label = new QLabel();
    QLabel* label2 = new QLabel();
    label2->setFixedSize(QSize(20,20));
    QString sty = "border-image:url("+res+");background-color: #00ffffff;";
    label->setStyleSheet("background-color: #00ffffff;font-size: 14px;font-family:Microsoft Yahei;font:#333333");
    label2 ->setStyleSheet(sty);

    label->setText(btnTxt);
    QHBoxLayout* myLayout = new QHBoxLayout();
    myLayout->addSpacing(10);
    myLayout->addWidget(label2);
    myLayout->addSpacing(10);
    myLayout->addWidget(label);
    myLayout->addStretch();
    btn->setLayout(myLayout);
    btn->setCheckable(true);
    return btn;
}

void NvrConfig::setControlPostion()
{

    int thisW = this->width();
    int thisH = this->height();

    int titleW = thisW;
    int titleH = 46;

    int menuW = 218;
    int menuH = thisH - titleH;
    int menuX = 0;
    int menuY = titleH;

    int spaceX = 1;
    int stackedWidgetW = thisW-menuW-spaceX;
    int stackedWidgetH = thisH-titleH;
    int stackedWidgetX = menuW+spaceX;
    int stackedWidgetY = titleH;

    ui->widget_menu->setGeometry(menuX,menuY,menuW,menuH);
    ui->widget_title->setGeometry(0,0,titleW,titleH);
    ui->stackedWidget->setGeometry(stackedWidgetX,stackedWidgetY,stackedWidgetW,stackedWidgetH);
}

NvrConfig::~NvrConfig()
{
    delete ui;
}
