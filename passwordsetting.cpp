#include "passwordsetting.h"
#include "ui_passwordsetting.h"

PasswordSetting::PasswordSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordSetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    setControlPostion();
}

PasswordSetting::~PasswordSetting()
{
    delete ui;
}


void PasswordSetting::setControlPostion()
{
    int labelW = 210;
    int labelH = 30;
    int labelY = 40;

    int label_2W = 270;
    int label_2H = 24;
    int label_2Y = 80;

    int lineEdit_passwordW = 312;
    int lineEdit_passwordH = 46;
    int lineEdit_passwordY = 134;

    int lineEdit_confirmW = 312;
    int lineEdit_confirmH = 46;
    int lineEdit_confirmY = 210;

    int btnW = 312;
    int btnH = 48;
    int btnY = 284;

    int thisW = this->width();
    int thisH = this->height();

    ui->label->setGeometry((thisW - labelW)/2,labelY,labelW,labelH);
    ui->label_2->setGeometry(QRect((thisW - label_2W)/2,label_2Y,label_2W,label_2H));

    ui->lineEdit_password->setGeometry((thisW - lineEdit_passwordW)/2,lineEdit_passwordY,lineEdit_passwordW,lineEdit_passwordH);
    ui->lineEdit_confirm->setGeometry((thisW - lineEdit_confirmW)/2,lineEdit_confirmY,lineEdit_confirmW,lineEdit_confirmH);

    ui->pushButton->setGeometry((thisW - btnW)/2,btnY,btnW,btnH);


}
