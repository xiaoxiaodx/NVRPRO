#include "systemmanager.h"
#include "ui_systemmanager.h"

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
    ui->TimeSetlabel_url->move(40,160);
    ui->TimeSetlineEdit_url->move(79,157);
    ui->TimeSetpushButton_url->move(291,159);

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
    ui->widget_3->setGeometry(0,0,950,518);




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
    ui->DiskmanagerprogressBar->move(185,194);
    ui->Diskmanagerlabel_storage_2->move(375,214);

}
void SystemManager::createSystemOperation()
{
    adjustSystemOperationWidgetPos();
}
void SystemManager::adjustSystemOperationWidgetPos()
{
    ui->widget_5->setGeometry(0,0,950,518);
    ui->Systemoperation_pushbutton_reboot->move(50,42);
    ui->Systemoperation_label_reboot->move(40,90);
    ui->Systemoperation_pushbutton_reset->move(161,42);
    ui->Systemoperation_label_reset->move(158,90);
}

void SystemManager::createUserManagement()
{
    adjustUserManagementWidgetPos();
}
void SystemManager::adjustUserManagementWidgetPos()
{
    ui->widget_6->setGeometry(0,0,950,518);

    ui->UserManagerlabel_title->move(20,20);
    ui->UserManagerline->move(20,52);

    ui->UserManagerlabel_oldpassword->move(70,76);
    ui->UserManagerlineEdit_oldpassword->move(174,73);
    ui->UserManagerlabel_newpassword->move(63,121);
    ui->UserManagerlineEdit_newpassword->move(174,118);
    ui->UserManagerlabel_confirmagain->move(65,169);
    ui->UserManagerlineEdit_confirmagain->move(174,166);
    ui->UserManagerpushButton_submit->move(279,204);
}

SystemManager::~SystemManager()
{
    delete ui;
}
