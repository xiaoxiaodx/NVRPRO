#include "dcalendardialog.h"
#include "ui_dcalendardialog.h"

DCalendarDialog::DCalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DCalendarDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);

    init();
    connect(ui->calendarWidget,SIGNAL(currentPageChanged(int, int)),this,SLOT(slot_currentPageChanged(int, int)));
    ui->calendarWidget->setFocusPolicy(Qt::NoFocus);
    ui->label_monthyear->setText(monthNumber2English(ui->calendarWidget->monthShown())+" "+QString::number(ui->calendarWidget->yearShown()));

    ui->calendarWidget_2->setFocusPolicy(Qt::NoFocus);
    connect(ui->calendarWidget_2,SIGNAL(currentPageChanged(int, int)),this,SLOT(slot_currentPageChanged2(int, int)));
    ui->label_monthyear_2->setText(monthNumber2English(ui->calendarWidget->monthShown())+" "+QString::number(ui->calendarWidget->yearShown()));


    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(slot_currentSelectChange()));
    connect(ui->calendarWidget_2,SIGNAL(selectionChanged()),this,SLOT(slot_currentSelectChange2()));

}

void DCalendarDialog::init()
{
    ui->line1->setGeometry(0,31,485,1);
    ui->line_2->setGeometry(0,67,485,1);
    ui->label_time->move(10,7);
    ui->label__->move(80,7);
    ui->label_time2->move(96,7);
    ui->pushButton_cancel->move(385,6);
    ui->pushButton_done->move(444,6);

    ui->pushButton_yearpre->move(13,46);
    ui->pushButton_monsepre->move(32,46);
    ui->pushButton_monthnext->move(199,46);
    ui->pushButton_yearnext->move(217,46);

    ui->pushButton_yearpre_2->move(257,46);
    ui->pushButton_monsepre_2->move(277,46);
    ui->pushButton_monthnext_2->move(440,46);
    ui->pushButton_yearnext_2->move(460,46);


    ui->label_monthyear->move(74,42);
    ui->label_monthyear_2->move(314,42);



    ui->calendarWidget->move(10,73);
    ui->calendarWidget_2->move(252,73);
}


QString DCalendarDialog::monthNumber2English(int month)
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

void DCalendarDialog::slot_currentPageChanged(int year, int month)
{
    QString monthEnglish = monthNumber2English(month);
    QString monthyear = monthEnglish + " "+ QString::number(year);
    ui->label_monthyear->setText(monthyear);
}

void DCalendarDialog::slot_currentPageChanged2(int year, int month)
{
    QString monthEnglish = monthNumber2English(month);
    QString monthyear = monthEnglish + " "+ QString::number(year);
    ui->label_monthyear_2->setText(monthyear);
}

void DCalendarDialog::slot_currentSelectChange()
{
    QDate date = ui->calendarWidget->selectedDate();
    ui->label_time->setText(date.toString("yy/MM/dd"));
}

void DCalendarDialog::slot_currentSelectChange2()
{
    QDate date = ui->calendarWidget_2->selectedDate();
    ui->label_time2->setText(date.toString("yyyy/MM/dd"));
}
DCalendarDialog::~DCalendarDialog()
{
    delete ui;
}

void DCalendarDialog::on_pushButton_done_clicked()
{

    emit signal_dateUpdate(ui->label_time->text(),ui->label_time2->text());
}

void DCalendarDialog::on_pushButton_yearpre_clicked()
{
    ui->calendarWidget->showPreviousYear();
}

void DCalendarDialog::on_pushButton_monsepre_clicked()
{
    ui->calendarWidget->showPreviousMonth();
}

void DCalendarDialog::on_pushButton_monthnext_clicked()
{
    ui->calendarWidget->showNextMonth();
}

void DCalendarDialog::on_pushButton_yearnext_clicked()
{
    ui->calendarWidget->showNextYear();
}

void DCalendarDialog::on_pushButton_yearpre_2_clicked()
{
    ui->calendarWidget_2->showPreviousYear();
}

void DCalendarDialog::on_pushButton_monsepre_2_clicked()
{
    ui->calendarWidget_2->showPreviousMonth();
}

void DCalendarDialog::on_pushButton_monthnext_2_clicked()
{
    ui->calendarWidget_2->showNextMonth();
}

void DCalendarDialog::on_pushButton_yearnext_2_clicked()
{
    ui->calendarWidget_2->showNextYear();
}
