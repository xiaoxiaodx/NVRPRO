#include "devicesetting.h"
#include "ui_devicesetting.h"
#include <QHeaderView>
#include <QScrollBar>
#include <QPushButton>
#include <QSpinBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QButtonGroup>
#include "confirmdialog.h"
#include "mainwindow.h"
#include "messagedialog.h"
DeviceSetting::DeviceSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeviceSetting)
{
    ui->setupUi(this);

    init();
}

void DeviceSetting::init()
{
    QMap<QString,QVariant> map;
    map.insert("isSelect",true);
    map.insert("did","11111");
    map.insert("name","2222");
    map.insert("status",true);
    map.insert("softwareVersion","5555");
    map.insert("hardwareVersion","66666");

    ui->label_title->move(15,16);
    ui->tabWidget->setGeometry(15,56,950,552);

    //第一页

    createDeviceTable();
    createDeviceTableHeader();

    createOSDSetting();
    adjustOSDWidgetPos();

    createAlarmSetting();
    adjustAlarmWidgetPos();

    createVideoSetting();
    adjustVideoWidgetPos();

    createRTMPSetting();
    adjustRTMPWidgetPos();

    deviceTableInsert(1,map);


    qDebug()<< "111:"<< ui->tableWidget->columnCount() ;
    qDebug()<< "111:"<< ui->tableWidget->rowCount() ;

//    QLabel *lable =static_cast<QLabel*>(ui->tableWidget->cellWidget(1,1));

    qDebug()<<"test1111111111111:"<<ui->tableWidget->item(1,1)->text();

}
//由于表头的自定义麻烦 故将第一行作为表头数据
void DeviceSetting::createDeviceTableHeader()
{
    int row_count = 0;

    QWidget *widget3 = new QWidget(this);
    QLabel *lable = new QLabel("Status",widget3);
    QPushButton *btn = new QPushButton(widget3);

    btn->setFocusPolicy(Qt::NoFocus);
    lable->setGeometry(0,10,36,15);
    btn ->setStyleSheet("QPushButton{border-image: url(:/images/table_menu.png);}"
                        "QPushButton:pressed{border-image: url(:/images/table_menu_p.png);}"
                        "QPushButton:hovered{border-image: url(:/images/table_menu_hover.png);}");
    btn->setGeometry(40,13,12,12);

    QLabel *lable0 = new QLabel("");
    QLabel *lable1 = new QLabel(tr("DID"));
    QLabel *lable2 = new QLabel(tr("Device Name"));
    QLabel *lable4 = new QLabel(tr("Software Version"));
    QLabel *lable5 = new QLabel(tr("Hardware Version"));
    QLabel *lable6 = new QLabel(tr("Operate"));



    widget3->setStyleSheet("background-color:#EBECF0;");
    lable0->setStyleSheet("background-color:#EBECF0;");
    lable1->setStyleSheet("background-color:#EBECF0;");
    lable2->setStyleSheet("background-color:#EBECF0;");
    lable4->setStyleSheet("background-color:#EBECF0;");
    lable5->setStyleSheet("background-color:#EBECF0;");
    lable6->setStyleSheet("background-color:#EBECF0;");


    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setRowHeight(row_count,35);
    ui->tableWidget->setCellWidget(row_count, 0,lable0);
    ui->tableWidget->setCellWidget(row_count, 1,lable1);
    ui->tableWidget->setCellWidget(row_count, 2,lable2);
    ui->tableWidget->setCellWidget(row_count, 3,widget3);
    ui->tableWidget->setCellWidget(row_count, 4,lable4);
    ui->tableWidget->setCellWidget(row_count, 5,lable5);
    ui->tableWidget->setCellWidget(row_count, 6,lable6);
}

void DeviceSetting::deviceTableInsert(int row_count,QMap<QString,QVariant> map)
{
    //int row_count = table_widget->rowCount(); //获取表单行数

    ui->tableWidget->insertRow(row_count); //插入新行

    QTableWidgetItem *item1 = new QTableWidgetItem();
    QTableWidgetItem *item2 = new QTableWidgetItem();
    QTableWidgetItem *item3 = new QTableWidgetItem();
    QTableWidgetItem *item4 = new QTableWidgetItem();
    QTableWidgetItem *item5 = new QTableWidgetItem();
    QTableWidgetItem *item6 = new QTableWidgetItem();


    QWidget *widget = new QWidget();
    widget->setStyleSheet("background-color:transparent");
    QPushButton *btnChecked = new QPushButton(widget);
    btnChecked->setCheckable(true);
    btnChecked ->setStyleSheet("QPushButton{border-image: url(:/images/device_unselect.png);}"
                               "QPushButton:checked{border-image: url(:/images/device_select.png);}");
    btnChecked->setGeometry(20,13,12,12);


    item1->setText(map.value("did").toString());
    item2->setText(map.value("name").toString());

    if(map.value("status").toBool()){
        item3->setIcon(QIcon(QPixmap(":/images/status_connect.png").scaled(8,8)));
        item3->setText("Connected");
    }else {
        item3->setIcon(QIcon(QPixmap(":/images/status_disconnect.png").scaled(8,8)));
        item3->setText("Disconnect");
    }
    item4->setText(map.value("softwareVersion").toString());
    item5->setText(map.value("hardwareVersion").toString());
    item6->setText("Delete");


    QPushButton *pbtnDelete = new QPushButton(tr("Delete"));
    pbtnDelete->setStyleSheet("text-align:left;background-color:transparent;border:none;color:#476BFD;font:bold 12px;");

    //    connect(pbtnDelete,&QPushButton::clicked,[=](){
    //        showDialog(row_count);
    //    });


    ui->tableWidget->setRowCount(row_count+1);
    ui->tableWidget->setRowHeight(row_count,35);
    ui->tableWidget->setCellWidget(row_count, 0, widget);
    ui->tableWidget->setItem(row_count, 1, item1);
    ui->tableWidget->setItem(row_count, 2, item2);
    ui->tableWidget->setItem(row_count, 3, item3);
    ui->tableWidget->setItem(row_count, 4, item4);
    ui->tableWidget->setItem(row_count, 5, item5);
    ui->tableWidget->setCellWidget(row_count, 6, pbtnDelete);
}

void DeviceSetting::showDialog(int deleteIndex)
{
    qDebug()<<"准备删除"<<deleteIndex<<"行,ps:表头是第0行";

    ConfirmDialog *dialog = new ConfirmDialog(this);
    dialog->setGeometry(256,234,300,110);
    dialog->show();
}

void DeviceSetting::createDeviceTable()
{

    ui->widget->setGeometry(0,0,950,518);
    ui->tableWidget->setGeometry(16,16,900,400);
  //  ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(7); //设置列数





    ui->tableWidget->horizontalHeader()->setVisible(false);


   ui->tableWidget->horizontalHeader()->resizeSection(0,84);
   ui->tableWidget->horizontalHeader()->resizeSection(1,132);
   ui->tableWidget->horizontalHeader()->resizeSection(2,120);
   ui->tableWidget->horizontalHeader()->resizeSection(3,132);
   ui->tableWidget->horizontalHeader()->resizeSection(4,146);
   ui->tableWidget->horizontalHeader()->resizeSection(5,140);
   ui->tableWidget->horizontalHeader()->resizeSection(6,81);

    ui->tableWidget->verticalHeader()->setDefaultSectionSize(2); //设置行距
    ui->tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见

    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    ui->tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框
    ui->tableWidget->setShowGrid(false); //设置不显示格子线

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选（Ctrl、Shift、 Ctrl+A都可以）
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    ui->tableWidget->setStyleSheet("color:#333333;background-color:#F9F9F9;selection-background-color:#F1F4FF;"); //设置背景色
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    //设置水平、垂直滚动条样式
    ui->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
                                                          "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                          "QScrollBar::handle:hover{background:gray;}"
                                                          "QScrollBar::sub-line{background:transparent;}"
                                                          "QScrollBar::add-line{background:transparent;}");
    ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
                                                        "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                        "QScrollBar::handle:hover{background:gray;}"
                                                        "QScrollBar::sub-line{background:transparent;}"
                                                        "QScrollBar::add-line{background:transparent;}");

}


void DeviceSetting::createOSDSetting()
{
    adjustOSDWidgetPos();
    ui->OSDlineEdit_cam1->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->OSDlineEdit_cam2->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->OSDlineEdit_cam3->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->OSDlineEdit_cam4->installEventFilter(MainWindow::EditKeyEventFilter);
}

void DeviceSetting::adjustOSDWidgetPos()
{

    ui->widget_2->setGeometry(0,0,950,518);
    ui->OSDlabel_timedisplay->move(20,20);
    ui->OSDline->setGeometry(20,52,910,1);
    ui->OSDlabel_swith_timeDisplay->move(40,73);
    ui->OSDswith_timeDisplay->move(104,73);


    ui->OSDpushButton_cam1->move(40,119);
    ui->OSDpushButton_cam2->move(129,119);
    ui->OSDpushButton_cam3->move(218,119);
    ui->OSDpushButton_cam4->move(307,119);

    ui->OSDlabel_cam1->move(66,115);
    ui->OSDlabel_cam2->move(155,115);
    ui->OSDlabel_cam3->move(244,115);
    ui->OSDlabel_cam4->move(333,115);

    ui->OSDlabel_namediplay->move(20,177);
    ui->OSDline_2->setGeometry(20,209,910,1);

    ui->OSDlabel_swith_nameDisplay->move(40,230);
    ui->OSDswith_nameDisplay->move(104,230);

    ui->OSDlabel_cam_1->move(40,275);
    ui->OSDlabel_cam_2->move(359,275);
    ui->OSDlabel_cam_3->move(40,323);
    ui->OSDlabel_cam_4->move(359,323);

    ui->OSDlineEdit_cam1->move(139,272);
    ui->OSDlineEdit_cam2->move(458,272);
    ui->OSDlineEdit_cam3->move(139,320);
    ui->OSDlineEdit_cam4->move(458,320);
    ui->OSDpushButton_submit->move(ui->OSDlineEdit_cam4->x()+ui->OSDlineEdit_cam4->width()-ui->OSDpushButton_submit->width(),ui->OSDlineEdit_cam4->y() +ui->OSDlineEdit_cam4->height() + 20);

}



void DeviceSetting::createAlarmSetting()
{
    ui->widget_3->setGeometry(0,0,950,518);
    adjustAlarmWidgetPos();
}
void DeviceSetting::adjustAlarmWidgetPos()
{

    ui->Alarmlabel_setting->move(20,20);
    ui->Alarmline->move(20,52);

    ui->Alarmlabel_cam_1->move(40,73);
    ui->Alarmlabel_motionDetection_1->move(139,73);
    ui->Alarmswitch_motionDetection_1->move(113,77);
    ui->Alarmlabel_videoloss_1->move(304,73);
    ui->Alarmswitch_videoloss_1->move(278,77);

    ui->Alarmlabel_cam_2->move(40,105);
    ui->Alarmlabel_motionDetection_2->move(139,105);
    ui->Alarmswitch_motionDetection_2->move(113,109);
    ui->Alarmlabel_videoloss_2->move(304,105);
    ui->Alarmswitch_videoloss_2->move(278,109);

    ui->Alarmlabel_cam_3->move(40,137);
    ui->Alarmlabel_motionDetection_3->move(139,137);
    ui->Alarmswitch_motionDetection_3->move(113,141);
    ui->Alarmlabel_videoloss_3->move(304,137);
    ui->Alarmswitch_videoloss_3->move(278,141);

    ui->Alarmlabel_cam_4->move(40,169);
    ui->Alarmlabel_motionDetection_4->move(139,169);
    ui->Alarmswitch_motionDetection_4->move(113,173);
    ui->Alarmlabel_videoloss_4->move(304,169);
    ui->Alarmswitch_videoloss_4->move(278,173);


    ui->Alarmlabel_alarmtime->move(23,231);
    ui->Alarmline_2->move(23,263);

    ui->Alarmlabel_siren->move(20,413);
    ui->Alarmline_3->move(20,445);
    ui->Alarmlabel_swith->move(40,466);
    ui->Alarmswitch->move(102,470);
}

void DeviceSetting::createVideoSetting()
{
    ui->widget_4->setGeometry(0,0,950,518);
    adjustVideoWidgetPos();
}
void DeviceSetting::adjustVideoWidgetPos()
{
    ui->Videolabel_setting->move(20,20);
    ui->Videoline->move(20,52);
    ui->VideopushButton_cam1->move(40,77);
    ui->Videolabel_cam1->move(66,73);
    ui->VideopushButton_cam2->move(129,77);
    ui->Videolabel_cam2->move(155,73);
    ui->VideopushButton_cam3->move(218,77);
    ui->Videolabel_cam3->move(244,73);
    ui->VideopushButton_cam4->move(307,77);
    ui->Videolabel_cam4->move(333,73);

    ui->VideolpushButton_recordingoff->move(40,119);
    ui->Videolabel_recordingoff->move(66,115);
    ui->VideopushButton_alarm->move(185,119);
    ui->Videolabel_alarm->move(211,115);
    ui->VideopushButton_wholedayrecording->move(314,119);
    ui->Videolabel_wholedayrecording->move(340,115);

    ui->Videolabel_resolution->move(40,170);
    ui->VideocomboBox->move(124,163);
    ui->VideocomboBox->setView(new QListView());

    ui->Videolabel_AlarmTime->move(30,235);
    ui->Videoline_2->move(20,267);
}
void DeviceSetting::createRTMPSetting()
{
    ui->widget_5->setGeometry(0,0,950,518);
    adjustRTMPWidgetPos();

    ui->RTMPlineEdit_url->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->RTMPlineEdit_username->installEventFilter(MainWindow::EditKeyEventFilter);
    ui->RTMPlineEdit_password->installEventFilter(MainWindow::EditKeyEventFilter);
}
void DeviceSetting::adjustRTMPWidgetPos()
{
    ui->RTMPlabel_setting->move(20,20);
    ui->RTMPline->move(20,52);

    ui->RTMPlabel_swith->move(36,73);
    ui->RTMPswith->move(100,77);
    ui->RTMPpushButton_cam1->move(40,119);
    ui->RTMPlabel_cam1->move(66,115);
    ui->RTMPpushButton_cam2->move(129,119);
    ui->RTMPlabel_cam2->move(155,115);
    ui->RTMPpushButton_cam3->move(218,119);
    ui->RTMPlabel_cam3->move(244,115);
    ui->RTMPpushButton_cam4->move(307,119);
    ui->RTMPlabel_cam4->move(333,115);

    ui->RTMPlabel_resolution->move(40,166);
    ui->RTMPcomboBox->move(124,163);
    ui->RTMPcomboBox->setView(new QListView());

    ui->RTMPlabel_url->move(85,234);
    ui->RTMPlineEdit_url->move(124,231);
    ui->RTMPlabel_username->move(37,279);
    ui->RTMPlineEdit_username->move(124,276);
    ui->RTMPlabel_password->move(48,327);
    ui->RTMPlineEdit_password->move(124,324);

    ui->RTMPpushButton_submit->move(ui->RTMPlineEdit_password->x() + ui->RTMPlineEdit_password->width() - ui->RTMPpushButton_submit->width(),ui->RTMPlineEdit_password->y()+ui->RTMPlineEdit_password->height()+20);

}
DeviceSetting::~DeviceSetting()
{
    delete ui;
}

void DeviceSetting::on_OSDpushButton_submit_clicked()
{

    MessageDialog *dialog = new MessageDialog(this,"输入错误 请重新输入");

    dialog->showDialogOnRight(ui->OSDpushButton_submit,20,1000);

}

void DeviceSetting::on_RTMPpushButton_submit_clicked()
{
    MessageDialog *dialog = new MessageDialog(this,"输入错误 请重新输入");

    dialog->showDialogOnRight(ui->RTMPpushButton_submit,20,1000);
}
