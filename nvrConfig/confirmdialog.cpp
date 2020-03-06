#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent,QString str) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint |Qt::Dialog);
    this->setModal(true);
    ui->label_askcontent->setText(str);
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

bool ConfirmDialog::showDialog()
{

    this->show();
    QEventLoop loop;
    connect(this, SIGNAL(finished(int)), &loop, SLOT(quit()));
    loop.exec();

    return isYes;
}


void ConfirmDialog::on_pushButton_confirm_clicked()
{
    isYes = true;
    this->close();
}

void ConfirmDialog::on_pushButton_cancel_clicked()
{
    isYes = false;
    this->close();
}

void ConfirmDialog::on_pushButton_close_clicked()
{
    isYes = false;
    this->close();
}
