#include "timezonesetting.h"
#include "ui_timezonesetting.h"
#include <QDebug>
#include <QStyledItemDelegate>
#include <QTime>
#include <QFile>
Timezonesetting::Timezonesetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timezonesetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    ui->comboBox->clear();

    QFile file(":/config/timezone.conf");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){

        QString allTimeZone = file.readAll();
        QStringList listTimeZone = allTimeZone.split("\n");
        for(int i=0;i<listTimeZone.size();i++){
            QString str= listTimeZone.at(i);
            ui->comboBox->addItem(str,str);
        }
    }

    QStyledItemDelegate* itemDelegate=new QStyledItemDelegate();
    ui->comboBox->setItemDelegate(itemDelegate);
    ui->comboBox->setMaxVisibleItems(5);

}

//所有控件水平居中,Y位置不同
void Timezonesetting::setControlPostion()
{

    int btnW = 312;
    int btnH = 46;
    int btnY = 264;

    int comboBoxW = 312;
    int comboBoxH = 46;
    int comboxY = 168;

    int labelW =160;
    int labelH = 38;
    int labelY = 70;

    int thisW = this->width();
    int thisH = this->height();

    ui->label->setGeometry((thisW - labelW)/2,labelY,labelW,labelH);
    ui->comboBox->setGeometry((thisW - comboBoxW)/2,comboxY,comboBoxW,comboBoxH);
    ui->pushButton_next->setGeometry((thisW - btnW)/2,btnY,btnW,btnH);
}

void Timezonesetting::setDefaultTimeZone(int index)
{
    ui->comboBox->setCurrentIndex(index);
}

Timezonesetting::~Timezonesetting()
{
    delete ui;
}

void Timezonesetting::on_pushButton_next_clicked()
{
    QString str = ui->comboBox->currentText();
    emit signal_timezoneStr(str);
}
