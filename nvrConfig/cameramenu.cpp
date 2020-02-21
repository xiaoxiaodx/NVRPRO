#include "cameramenu.h"
#include "ui_cameramenu.h"
#include <QDebug>
CameraMenu::CameraMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraMenu)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

void CameraMenu::enterEvent(QEvent *)
{
    qDebug()<<"Camera鼠标进入";
}
void CameraMenu::leaveEvent(QEvent *)
{
    qDebug()<<"Camera鼠标离开";
    this->hide();
}


CameraMenu::~CameraMenu()
{
    qDebug()<<"Camera菜单析构";
    delete ui;
}
