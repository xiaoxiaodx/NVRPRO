#include "timeselectdialog.h"
#include "ui_timeselectdialog.h"
#include <QStandardItemModel>
TimeSelectDialog::TimeSelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeSelectDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);

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

    ui->listView_hour->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_minute->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_seconds->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->listView_seconds->setFocusPolicy(Qt::NoFocus);
    ui->listView_minute->setFocusPolicy(Qt::NoFocus);
    ui->listView_hour->setFocusPolicy(Qt::NoFocus);

    for (int i=0;i<24;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter);
        hourItemModel->appendRow(item);
    }
    for (int i=0;i<60;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter);
        minItemModel->appendRow(item);
    }
    for (int i=0;i<60;i++) {
        QStandardItem *item = new QStandardItem(QString::number(i));
        item->setTextAlignment(Qt::AlignCenter);
        secsItemModel->appendRow(item);
    }

    ui->label_time->move(0,0);
    ui->listView_hour->move(0,32);
    ui->listView_minute->move(40,32);
    ui->listView_seconds->move(80,32);
    ui->pushButton_cancel->move(0,225);
    ui->pushButton_done->move(60,225);
}

void TimeSelectDialog::setInitTime(QTime time)
{

    ui->label_time->setText(time.toString("hh:mm:ss"));
}

QTime TimeSelectDialog::timeStr2QTime(QString str)
{
    QStringList listT = str.split(":");

    Q_ASSERT(listT.size() > 0);

    QTime time;
    time.setHMS(listT.at(0).toInt(),listT.at(1).toInt(),listT.at(2).toInt());
    return time;
}

TimeSelectDialog::~TimeSelectDialog()
{
    delete ui;
}

void TimeSelectDialog::on_listView_minute_clicked(const QModelIndex &index)
{
    QTime time = timeStr2QTime(ui->label_time->text());

    time.setHMS(time.hour(),0,time.second());

    int min = index.row();

    QTime newT = time.addSecs(min*60);

    ui->label_time->setText(newT.toString("hh:mm:ss"));


}

void TimeSelectDialog::on_listView_seconds_clicked(const QModelIndex &index)
{
    QTime time = timeStr2QTime(ui->label_time->text());

    time.setHMS(time.hour(),time.minute(),0);

    int sec = index.row();

    QTime newT = time.addSecs(sec);

    ui->label_time->setText(newT.toString("hh:mm:ss"));
}

void TimeSelectDialog::on_listView_hour_clicked(const QModelIndex &index)
{
    QTime time = timeStr2QTime(ui->label_time->text());

    time.setHMS(0,time.minute(),time.second());

    int hour = index.row();

    QTime newT = time.addSecs(hour*3600);

    ui->label_time->setText(newT.toString("hh:mm:ss"));
}

void TimeSelectDialog::on_pushButton_done_clicked()
{
    emit signal_timeChange(timeStr2QTime(ui->label_time->text()));
    this->close();
}

void TimeSelectDialog::on_pushButton_cancel_clicked()
{
    this->close();
}
