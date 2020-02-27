#include "welcome.h"
#include "ui_welcome.h"
#include "mainwindow.h"
Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{

    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setControlPostion();
}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::setControlPostion()
{
    int labelW = 152;
    int labelH = 38;
    int labelY = 70;

    int lineEdit_passwordW = 312;
    int lineEdit_passwordH = 46;
    int lineEdit_passwordY = 168;

    int btnW = 312;
    int btnH = 46;
    int btnY = 264;

    int thisW = this->width();
    int thisH = this->height();

    ui->label->setGeometry((thisW - labelW)/2,labelY,labelW,labelH);

    ui->lineEdit_password->installEventFilter(MainWindow::EditKeyEventFilter);

    ui->lineEdit_password->setGeometry((thisW - lineEdit_passwordW)/2,lineEdit_passwordY,lineEdit_passwordW,lineEdit_passwordH);

    ui->pushButton->setGeometry((thisW - btnW)/2,btnY,btnW,btnH);


}
