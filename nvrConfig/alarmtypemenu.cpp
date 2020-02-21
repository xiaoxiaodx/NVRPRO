#include "alarmtypemenu.h"
#include "ui_alarmtypemenu.h"
#include <QDebug>
AlarmTypeMenu::AlarmTypeMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmTypeMenu)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

}
void AlarmTypeMenu::enterEvent(QEvent *)
{
    qDebug()<<"鼠标进入";
}
void AlarmTypeMenu::leaveEvent(QEvent *)
{
    qDebug()<<"鼠标离开";
    this->hide();
}


AlarmTypeMenu::~AlarmTypeMenu()
{
    delete ui;
}
