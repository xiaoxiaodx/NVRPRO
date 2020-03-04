#include "deleteconfirmdialog.h"
#include "ui_deleteconfirmdialog.h"

DeleteConfirmDialog::DeleteConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteConfirmDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->label_askimg->move(23,36);
    ui->label_askcontent->move(49,38);
    ui->pushButton_close->move(280,11);
    ui->pushButton_confirm->move(194,78);
    ui->pushButton_cancel->move(246,78);
}

DeleteConfirmDialog::~DeleteConfirmDialog()
{
    delete ui;
}

void DeleteConfirmDialog::on_pushButton_cancel_clicked()
{
    this->close();
}

void DeleteConfirmDialog::on_pushButton_close_clicked()
{
    this->close();
}
