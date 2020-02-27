#include "mycalendar.h"
#include "ui_mycalendar.h"
#include <QDebug>
#include <QTextCharFormat>
MyCalendar::MyCalendar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyCalendar)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Popup);
    connect(ui->calendarWidget,SIGNAL(currentPageChanged(int, int)),this,SLOT(slot_currentPageChanged(int, int)));
    ui->calendarWidget->setFocusPolicy(Qt::NoFocus);
    ui->label_monthyear->setText(monthNumber2English(ui->calendarWidget->monthShown())+" "+QString::number(ui->calendarWidget->yearShown()));


    QTextCharFormat format = ui->calendarWidget->weekdayTextFormat(Qt::Sunday);
    format.setForeground(QBrush(QColor(0,0,0,165), Qt::SolidPattern));
    ui->calendarWidget->setWeekdayTextFormat(Qt::Saturday, format);
    QTextCharFormat format1 = ui->calendarWidget->weekdayTextFormat(Qt::Sunday);
    format1.setForeground(QBrush(QColor(0,0,0,165), Qt::SolidPattern));
    ui->calendarWidget->setWeekdayTextFormat(Qt::Sunday, format1);
}

MyCalendar::~MyCalendar()
{
    delete ui;
}
void MyCalendar::slot_currentPageChanged(int year, int month)
{
    qDebug()<<" date change:"<<year<<"  "<<month;

    //January ，February ， March ，April，May，June，July，August，September，October，November，December
    QString monthEnglish = monthNumber2English(month);
    QString monthyear = monthEnglish + " "+ QString::number(year);
    ui->label_monthyear->setText(monthyear);
}

QString MyCalendar::monthNumber2English(int month)
{
    switch (month) {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8  :
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        return "undefine";
    }
}

void MyCalendar::on_pushButton_yearnext_clicked()
{
    ui->calendarWidget->showNextYear();
}

void MyCalendar::on_pushButton_monthnext_clicked()
{
    ui->calendarWidget->showNextMonth();
}

void MyCalendar::on_pushButton_monsepre_clicked()
{
    ui->calendarWidget->showPreviousMonth();
}

void MyCalendar::on_pushButton_yearpre_clicked()
{
    ui->calendarWidget->showPreviousYear();
}

void MyCalendar::on_pushButton_done_clicked()
{
    emit dateUpdate(ui->calendarWidget->selectedDate());
    this->hide();
}

void MyCalendar::on_pushButton_cancel_clicked()
{
    this->hide();
}
