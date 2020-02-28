#include "timezonesetting.h"
#include "ui_timezonesetting.h"
#include <QDebug>
#include <QStyledItemDelegate>
Timezonesetting::Timezonesetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timezonesetting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    QMap<QString, int> City_Zone;
    City_Zone.insert("GMT+08:00北京",10);
    City_Zone.insert("GMT+08:00北京1",21);
    City_Zone.insert("GMT+08:00北京2",22);
    City_Zone.insert("GMT+08:00北京3",411);
    City_Zone.insert("GMT+08:00北京4",416);
    City_Zone.insert("GMT+08:00北京5",516);
    City_Zone.insert("GMT+08:00北京6",591);
    City_Zone.insert("GMT+08:00北京7",532);
    ui->comboBox->clear();

    QStyledItemDelegate* itemDelegate=new QStyledItemDelegate();
    ui->comboBox->setItemDelegate(itemDelegate);
    ui->comboBox->setMaxVisibleItems(5);
    foreach(const QString &str,City_Zone.keys())
        ui->comboBox->addItem(str,City_Zone.value(str));

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


Timezonesetting::~Timezonesetting()
{
    delete ui;
}

void Timezonesetting::on_pushButton_next_clicked()
{
    QString str = ui->comboBox->currentText();
    emit signal_timezoneStr(str);
}
