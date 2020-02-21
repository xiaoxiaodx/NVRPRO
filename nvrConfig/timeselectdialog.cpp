#include "timeselectdialog.h"
#include "ui_timeselectdialog.h"
#include <QStandardItemModel>
TimeSelectDialog::TimeSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSelectDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);

    init();
}

void TimeSelectDialog::init()
{
    QStandardItemModel  *hourItemModel = new QStandardItemModel(this);
    QStandardItemModel  *minItemModel = new QStandardItemModel(this);
    QStandardItemModel  *secsItemModel = new QStandardItemModel(this);


    ui->listView_hour->setModel(hourItemModel);
    ui->listView_minute->setModel(minItemModel);
    ui->listView_seconds->setModel(secsItemModel);

    for (int i=0;i<24;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));
        hourItemModel->appendRow(item);
    }
    for (int i=0;i<60;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));
        minItemModel->appendRow(item);

    }
    for (int i=0;i<60;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));

        secsItemModel->appendRow(item);
    }



}

TimeSelectDialog::~TimeSelectDialog()
{
    delete ui;
}
