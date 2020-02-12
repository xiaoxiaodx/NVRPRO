#include "osdsetting.h"
#include "ui_osdsetting.h"

OSDSetting::OSDSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OSDSetting)
{
    ui->setupUi(this);
}

OSDSetting::~OSDSetting()
{
    delete ui;
}
