#include "nvrconfig.h"
#include "ui_nvrconfig.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QDebug>
#include <QCoreApplication>
#include <QMouseEvent>

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
#include"virtualkeyboard.h"
#include <mainwindow.h>
void NvrConfig::initStackedWidget()
{

    if(deviceSetting == NULL){
        deviceSetting = new DeviceSetting(this);
        deviceSetting->installEventFilter(MainWindow::systemConfigEventFilter);
        ui->stackedWidget->addWidget(deviceSetting);
    }

    if(systemManager == NULL){
        systemManager = new SystemManager(this);
        systemManager->installEventFilter(MainWindow::systemConfigEventFilter);
        ui->stackedWidget->addWidget(systemManager);
    }
}

void NvrConfig::setMenuItem()
{
    btnMasterPreview = createSelfBtn("Master Preview",":/images/masterPreview.png");
    btnReplay= createSelfBtn("Video Replay",":/images/video_replay.png");
    btnDeviceSetting= createSelfBtn("Device Setting",":/images/device_setting.png");
    btnSystemManagement= createSelfBtn("System Management",":/images/system_manager.png");

    /*单选菜单效果*/
    QButtonGroup *buttonGround = new QButtonGroup(this);
    buttonGround->addButton(btnMasterPreview);
    buttonGround->addButton(btnReplay);
    buttonGround->addButton(btnDeviceSetting);
    buttonGround->addButton(btnSystemManagement);
    buttonGround->setExclusive(true);

    connect(btnMasterPreview,SIGNAL(clicked()),this,SLOT(slot_MenuSelectMasterPreview()));
    connect(btnReplay,SIGNAL(clicked()),this,SLOT(slot_MenuSelectReplay()));

    connect(btnDeviceSetting,SIGNAL(clicked()),this,SLOT(slot_MenuSelectDeviceSetting()));

    connect(btnSystemManagement,SIGNAL(clicked()),this,SLOT(slot_MenuSelectSystemManagement()));


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


void NvrConfig::slot_MenuSelectMasterPreview()
{
    emit signal_switchWindow(MASTERPREVIEW);
    //this->hide();
}
void NvrConfig::slot_MenuSelectReplay()
{
    emit signal_switchWindow(REPLAYVIDEO);
    //this->hide();
}
void NvrConfig::slot_MenuSelectDeviceSetting()
{
     ui->stackedWidget->setCurrentWidget(deviceSetting);
}
void NvrConfig::slot_MenuSelectSystemManagement()
{
     ui->stackedWidget->setCurrentWidget(systemManager);
}
void NvrConfig::showDeviceSet()
{
    if(deviceSetting != NULL){
        this->show();
        btnDeviceSetting->setChecked(true);
        ui->stackedWidget->setCurrentWidget(deviceSetting);
    }
}

void NvrConfig::showSystemSet()
{
    if(systemManager != NULL){
        this->show();
        btnSystemManagement->setChecked(true);
        ui->stackedWidget->setCurrentWidget(systemManager);
    }
}

QPushButton * NvrConfig::createSelfBtn(QString btnTxt,QString res)
{
    const QSize btnSize(218,36);
    QPushButton *btn = new QPushButton();

    btn->setFocusPolicy(Qt::NoFocus);
    btn ->setCheckable(true);
    btn ->setFixedSize(btnSize);
    btn ->setStyleSheet("QPushButton{background-color: #FFFFFF;border:none}"
                        "QPushButton:checked{background-color: #F1F4FF;}");
    QLabel* label = new QLabel();
    QLabel* label2 = new QLabel();
    label2->setFixedSize(QSize(20,20));
    QString sty = "border-image:url("+res+");background-color: rgba(0,0,0,0);";
    label->setStyleSheet("background-color:  rgba(0,0,0,0);font-size: 14px;font:#333333");
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
