#include "systemmanager.h"
#include "ui_systemmanager.h"
#include <QHeaderView>
#include <QScrollBar>
#include <QHBoxLayout>
#include "mainwindow.h"
SystemManager::SystemManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemManager)
{
    ui->setupUi(this);
    init();
}


void SystemManager::init()
{
    ui->label_title->move(15,16);
    ui->tabWidget->setGeometry(15,56,950,552);

    createTimeSetting();
    adjustTimeSettingWidgetPos();
    createSystemInfo();
    adjustSystemInfoWidgetPos();
    createAlarmQuery();
    adjustAlarmQueryWidgetPos();
    createDiskManagement();
    adjustDiskManagementWidgetPos();
    createSystemOperation();
    adjustSystemOperationWidgetPos();
    createUserManagement();
    adjustUserManagementWidgetPos();
}

void SystemManager::createTimeSetting()
{
    adjustTimeSettingWidgetPos();

    ui->TimeSetlineEdit_url->installEventFilter(MainWindow::EditKeyEventFilter);

}

void SystemManager::adjustTimeSettingWidgetPos()
{
    ui->widget->setGeometry(0,0,950,518);

    ui->TimeSetlabel_setting->move(20,20);
    ui->TimeSetline->move(20,52);
    ui->TimeSetlabel_swith_setting->move(40,73);
    ui->TimeSetswith_setting->move(104,77);

    ui->TimeSetpushButton_everyhour->move(40,119);
    ui->TimeSetlabel_everyhour->move(66,115);
    ui->TimeSetpushButton_everyday->move(160,119);
    ui->TimeSetlabel_everyday->move(186,115);
    ui->TimeSetpushButton_everyweek->move(272,119);
    ui->TimeSetlabel_everyweek->move(298,115);
    ui->TimeSetlabel_url->move(40,162);
    ui->TimeSetlineEdit_url->move(85,157);
    ui->TimeSetpushButton_url->move(297,159);

    ui->TimeSetlabel_summertime->move(20,225);
    ui->TimeSetline_1->move(20,257);
    ui->TimeSetcomboBox->move(40,278);


    ui->TimeSetlabel_savetime->move(20,346);
    ui->TimeSetline_2->move(20,378);
    ui->TimeSetlabel_swith_savetime->move(40,399);
    ui->TimeSetswith_timesave->move(104,403);

}
void SystemManager::createSystemInfo()
{
    adjustSystemInfoWidgetPos();
}

void SystemManager::adjustSystemInfoWidgetPos()
{
    ui->widget_2->setGeometry(0,0,950,518);

    ui->Systeminfolabel_systeminfo->move(20,20);
    ui->Systeminfoline->move(20,52);
    ui->Systeminfolabel_devicetype->move(75,73);
    ui->Systeminfolabel_devicetypeInput->move(169,74);
    ui->Systeminfolabel_devicedid->move(84,102);
    ui->Systeminfolabel_devicedidinput->move(169,102);
    ui->Systeminfolabel_softversion->move(46,131);
    ui->Systeminfolabel_softversioninput->move(169,132);
    ui->Systeminfolabel_hardwareversion->move(40,160);
    ui->Systeminfolabel_hardwareversioninput->move(169,161);

    ui->Systeminfolabel_networkinfo->move(20,219);
    ui->Systeminfoline_1->move(20,251);
    ui->Systeminfolabel_ipaddress->move(88,272);
    ui->Systeminfolabel_ipaddressinput->move(169,273);
    ui->Systeminfoabel_macaddress->move(72,301);
    ui->Systeminfolabel_macaddressinput->move(169,302);
}

void SystemManager::createAlarmQuery()
{
    adjustAlarmQueryWidgetPos();
}

void SystemManager::adjustAlarmQueryWidgetPos()
{

    QMap<QString,QVariant> map;
    map.insert("index",0);
    map.insert("camara","11111");
    map.insert("alarmType","Motion Detection");
    map.insert("startTime","2019-01-08 14:00:00");
    map.insert("endTime","2019-01-08 14:30:00");

    QMap<QString,QVariant> map1;
    map1.insert("index",1);
    map1.insert("camara","2222");
    map1.insert("alarmType","Disk exception");
    map1.insert("startTime","2019-01-08 14:00:00");
    map1.insert("endTime","2019-01-08 14:30:00");

    QMap<QString,QVariant> map2;
    map2.insert("index",2);
    map2.insert("camara","2222");
    map2.insert("alarmType","Video Loss");
    map2.insert("startTime","2019-01-09 14:00:00");
    map2.insert("endTime","2019-01-09 14:30:00");


    ui->widget_3->setGeometry(0,0,950,518);

    ui->label_title_alarm->move(20,20);
    ui->tableWidget_2->move(20,52);
    ui->widget_date->move(479,16);
    ui->widget_time->move(717,16);

    createAlarmQueryTable();
    createDeviceTableHeader();
    alarmQueryTableInsert(1,map);
    alarmQueryTableInsert(2,map1);
    alarmQueryTableInsert(3,map2);


}

void SystemManager::createAlarmQueryTable()
{

    ui->tableWidget_2->setGeometry(20,52,815,400);
    ui->tableWidget_2->setRowCount(3);
    ui->tableWidget_2->setColumnCount(5); //设置列数


    // ui->tableWidget_2->horizontalHeader()->setDefaultSectionSize(130);
    ui->tableWidget_2->horizontalHeader()->resizeSection(0,114);
    ui->tableWidget_2->horizontalHeader()->resizeSection(1,130);
    ui->tableWidget_2->horizontalHeader()->resizeSection(2,206);
    ui->tableWidget_2->horizontalHeader()->resizeSection(3,210);
    ui->tableWidget_2->horizontalHeader()->resizeSection(4,150);

    ui->tableWidget_2->horizontalHeader()->setFixedHeight(31); //设置表头的高度

    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{border:none;font:bold;background:#EBECF0;}"); //设置表头背景色
    ui->tableWidget_2->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    ui->tableWidget_2->horizontalHeader()->setVisible(false); //设置垂直头不可见
    ui->tableWidget_2->verticalHeader()->setDefaultSectionSize(2); //设置行距
    ui->tableWidget_2->verticalHeader()->setVisible(false); //设置垂直头不可见


    ui->tableWidget_2->setFrameShape(QFrame::NoFrame);
    ui->tableWidget_2->setFrameShape(QFrame::NoFrame); //设置无边框
    ui->tableWidget_2->setShowGrid(false); //设置不显示格子线

    ui->tableWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、 Ctrl+A都可以）
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    ui->tableWidget_2->setStyleSheet("background-color:#F9F9F9;selection-background-color:#F1F4FF;"); //设置背景色
    ui->tableWidget_2->setFocusPolicy(Qt::NoFocus);

    //设置水平、垂直滚动条样式
    ui->tableWidget_2->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
                                                            "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                            "QScrollBar::handle:hover{background:gray;}"
                                                            "QScrollBar::sub-line{background:transparent;}"
                                                            "QScrollBar::add-line{background:transparent;}");
    ui->tableWidget_2->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
                                                          "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                          "QScrollBar::handle:hover{background:gray;}"
                                                          "QScrollBar::sub-line{background:transparent;}"
                                                          "QScrollBar::add-line{background:transparent;}");

}

//由于表头的自定义麻烦 故将第一行作为表头数据
void SystemManager::createDeviceTableHeader()
{
    int row_count = 0;

    QLabel *lable1 = new QLabel("S/N");

    lable1->setAlignment(Qt::AlignCenter);


    QWidget *widget2 = new QWidget(this);
    QLabel *lable2 = new QLabel("Camera",widget2);
    QPushButton *btn2 = new QPushButton(widget2);
    lable2->setGeometry(0,10,44,15);
    btn2->setGeometry(50,13,10,10);
    btn2 ->setStyleSheet("QPushButton{border-image: url(:/images/table_menu.png);}"
                         "QPushButton:pressed{border-image: url(:/images/table_menu_p.png);}");


    connect(btn2,SIGNAL(clicked()),this,SLOT(slot_channelMenuClick()));

    QWidget *widget3 = new QWidget(this);
    QLabel *lable3 = new QLabel("Alarm Typle",widget3);
    QPushButton *btn3 = new QPushButton(widget3);
    lable3->setGeometry(0,10,69,15);
    btn3->setGeometry(73,13,10,10);
    btn3 ->setStyleSheet("QPushButton{border-image: url(:/images/table_menu.png);}"
                         "QPushButton:pressed{border-image: url(:/images/table_menu_p.png);}");

    connect(btn3,SIGNAL(clicked()),this,SLOT(slot_alarmTypeMenuClick()));

    QWidget *widget4 = new QWidget(this);
    QLabel *lable4 = new QLabel("Start Time",widget4);
    QPushButton *btn4up = new QPushButton(widget4);
    QPushButton *btn4down = new QPushButton(widget4);
    lable4->setGeometry(0,10,59,15);
    btn4up->setGeometry(63,12,10,6);
    btn4down->setGeometry(63,19,10,6);
    btn4up ->setStyleSheet("QPushButton{border-image: url(:/images/table_up.png);}"
                           "QPushButton:pressed{border-image: url(:/images/table_up_p.png);}");
    btn4down ->setStyleSheet("QPushButton{border-image: url(:/images/table_down.png);}"
                             "QPushButton:pressed{border-image: url(:/images/table_down_p.png);}");

    QWidget *widget5 = new QWidget(this);
    QLabel *lable5 = new QLabel("End Time",widget5);
    QPushButton *btn5up = new QPushButton(widget5);
    QPushButton *btn5down = new QPushButton(widget5);
    lable5->setGeometry(0,10,54,15);

    btn5up->setGeometry(58,12,10,6);
    btn5down->setGeometry(58,19,10,6);
    btn5up ->setStyleSheet("QPushButton{border-image: url(:/images/table_up.png);}"
                           "QPushButton:pressed{border-image: url(:/images/table_up_p.png);}");

    btn5down ->setStyleSheet("QPushButton{border-image: url(:/images/table_down.png);}"
                             "QPushButton:pressed{border-image: url(:/images/table_down_p.png);}");


    lable1->setStyleSheet("background-color:#EDEDED;");
    widget2->setStyleSheet("background-color:#EDEDED;");
    widget3->setStyleSheet("background-color:#EDEDED;");
    widget4->setStyleSheet("background-color:#EDEDED;");
    widget5->setStyleSheet("background-color:#EDEDED;");


    ui->tableWidget_2->setRowHeight(row_count,35);
    ui->tableWidget_2->setCellWidget(row_count, 0,lable1);
    ui->tableWidget_2->setCellWidget(row_count, 1,widget2);
    ui->tableWidget_2->setCellWidget(row_count, 2,widget3);
    ui->tableWidget_2->setCellWidget(row_count, 3,widget4);
    ui->tableWidget_2->setCellWidget(row_count, 4,widget5);
}

void SystemManager::slot_channelMenuClick()
{
    if(cameraChannelMenu == NULL){
        cameraChannelMenu = new CameraMenu(ui->widget_3);
        cameraChannelMenu->move(157,70);
    }
    cameraChannelMenu->show();
}
void SystemManager::slot_alarmTypeMenuClick()
{
    if(alarmtypeMenu == NULL){
        alarmtypeMenu = new AlarmTypeMenu(ui->widget_3);
        alarmtypeMenu->move(302,70);
    }
    alarmtypeMenu->show();
}
void SystemManager::alarmQueryTableInsert(int row_count,QMap<QString,QVariant> map)
{
    //int row_count = table_widget->rowCount(); //获取表单行数

    ui->tableWidget_2->insertRow(row_count); //插入新行


    QLabel *lable0 = new QLabel(QString::number(map.value("index").toInt()));

    lable0->setAlignment(Qt::AlignCenter);
    lable0->setStyleSheet("background-color:transparent");

    QTableWidgetItem *item1 = new QTableWidgetItem(map.value("camara").toString());

    QWidget *widget2 = NULL;
    QTableWidgetItem *item2 = NULL;
    if(map.value("alarmType").toString().compare("Motion Detection")==0){
        widget2 = new QWidget(this);
        QLabel *lable2 = new QLabel("Motion Detection",widget2);
        QPushButton *btn2 = new QPushButton(widget2);
        lable2->setGeometry(3,8,102,15);

        btn2->setGeometry(114,11,12,12);
        btn2 ->setStyleSheet("QPushButton{border-image: url(:/images/table_play.png);}"
                             "QPushButton:pressed{border-image: url(:/images/table_play_p.png);}");
        widget2->setStyleSheet("background-color:transparent");
    }else {
        item2 = new QTableWidgetItem(map.value("alarmType").toString());
    }


    QTableWidgetItem *item3 = new QTableWidgetItem(map.value("startTime").toString());
    QTableWidgetItem *item4 = new QTableWidgetItem(map.value("endTime").toString());


    // ui->tableWidget->setItem(row_count, 0, item0);

    //    QPushButton *pbtnDelete = new QPushButton(tr("Delete"));
    //    pbtnDelete->setStyleSheet("text-align:left;background-color:transparent;border:none;color:#476BFD;font:bold 12px;");

    //    connect(pbtnDelete,&QPushButton::clicked,[=](){

    //    });


    ui->tableWidget_2->setCellWidget(row_count, 0, lable0);
    ui->tableWidget_2->setItem(row_count, 1, item1);
    if(map.value("alarmType").toString().compare("Motion Detection")==0){
        if(widget2 != NULL)
            ui->tableWidget_2->setCellWidget(row_count, 2, widget2);
    }else{
        if(item2 != NULL)
            ui->tableWidget_2->setItem(row_count, 2, item2);
    }
    ui->tableWidget_2->setItem(row_count, 3, item3);
    ui->tableWidget_2->setItem(row_count, 4, item4);
    ui->tableWidget_2->setRowHeight(row_count,35);
}

void SystemManager::createDiskManagement()
{
    adjustDiskManagementWidgetPos();
}
void SystemManager::adjustDiskManagementWidgetPos()
{
    ui->widget_4->setGeometry(0,0,950,518);

    ui->Diskmanagerlabel_diskerr->move(20,20);
    ui->Diskmanagerline->move(20,52);
    ui->Diskmanagerlabel_swith->move(40,73);
    ui->Diskmanagerswith->move(104,77);
    ui->Diskmanagerlabel_hderr->move(20,135);
    ui->Diskmanagerline_1->move(20,167);
    ui->Diskmanagerlabel_storage->move(40,189);
    ui->DiskmanagerprogressBar->move(181,194);
    ui->Diskmanagerlabel_storage_2->move(375,212);
}

void SystemManager::createSystemOperation()
{
    adjustSystemOperationWidgetPos();
}
void SystemManager::adjustSystemOperationWidgetPos()
{
    ui->widget_5->setGeometry(0,0,950,518);
    ui->Systemoperation_pushbutton_reboot->move(50,42);
    ui->Systemoperation_label_reboot->move(44,90);
    ui->Systemoperation_pushbutton_reset->move(161,42);
    ui->Systemoperation_label_reset->move(160,90);
}

void SystemManager::createUserManagement()
{
    adjustUserManagementWidgetPos();

    ui->UserManagerlineEdit_oldpassword->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->UserManagerlineEdit_newpassword->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->UserManagerlineEdit_confirmagain->installEventFilter(MainWindow::EditKeyEventFilter);
}
void SystemManager::adjustUserManagementWidgetPos()
{
    ui->widget_6->setGeometry(0,0,950,518);

    ui->UserManagerlabel_title->move(20,20);
    ui->UserManagerline->move(20,52);

    ui->UserManagerlabel_oldpassword->move(70,76);
    ui->UserManagerlineEdit_oldpassword->move(174,73);
    ui->UserManagerlabel_newpassword->move(70,124);
    ui->UserManagerlineEdit_newpassword->move(174,121);
    ui->UserManagerlabel_confirmagain->move(65,172);
    ui->UserManagerlineEdit_confirmagain->move(174,169);
    ui->UserManagerpushButton_submit->move(279,217);
}

SystemManager::~SystemManager()
{
    delete ui;
}

void SystemManager::on_pushButton_date_clicked()
{
    popCalendar();
}

void SystemManager::popCalendar()
{
    if(myCalendar == NULL){
        myCalendar = new DCalendarDialog(this);
        myCalendar->setModal(true);
        QPoint dateScreenPos = ui->widget_date->mapToGlobal(QPoint(0,0));
        myCalendar->setGeometry(dateScreenPos.x()-(484-ui->widget_date->width())/2,375+ui->widget_date->height(),484,270);


        connect(myCalendar,SIGNAL(signal_dateUpdate(QString ,QString )),this,SLOT(slot_dateChange(QString ,QString )));
    }
    myCalendar->show();
}

void SystemManager::slot_dateChange(QString  datestr1,QString  datestr2)
{
    ui->label_startDate->setText(datestr1);
    ui->label_endDate->setText(datestr2);
}

void SystemManager::on_pushButton_time_clicked()
{
    if(timeSelectDialog == NULL){
        timeSelectDialog = new TimeSelectDialog(this);

        QPoint widget_timeScreenPos = ui->widget_time->mapToGlobal(QPoint(0,0));
        timeSelectDialog->setGeometry(widget_timeScreenPos.x(),widget_timeScreenPos.y()+ui->widget_time->height(),120,254);

        connect(timeSelectDialog,SIGNAL(signal_timeChange(QTime )),this,SLOT(slot_timeChange(QTime )));
    }


    QTime time = TimeSelectDialog::timeStr2QTime(ui->label_time->text());

    timeSelectDialog->setInitTime(time);
    timeSelectDialog->show();


}

void SystemManager::slot_timeChange(QTime time)
{
    ui->label_time->setText(time.toString("hh:mm::ss"));
}

#include "customerevent.h"

void SystemManager::on_TimeSetpushButton_url_clicked()
{
    CustomerEvent *event= new CustomerEvent(BELONG_SYSTEMSET,TYPE_SYSTEMSET_TEST1,2);

    bool result = QCoreApplication::sendEvent(this, event);

    Q_ASSERT(result);

    delete event;

}

bool SystemManager::event(QEvent *event)
{
    qDebug()<<"dsadsa";

}


void SystemManager::setText(QString str)
{
    ui->TimeSetlineEdit_url->setText(str);
}
