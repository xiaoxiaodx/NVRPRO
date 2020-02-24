#include "dcalendardialog.h"
#include "ui_dcalendardialog.h"

DCalendarDialog::DCalendarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DCalendarDialog)
{
    ui->setupUi(this);


     init();
}

void DCalendarDialog::init()
{
    ui->line1->setGeometry(0,31,485,1);
    ui->line_2->setGeometry(0,67,485,1);
    ui->label_time->move(10,7);
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

    ui->calendarWidget->move(20,83);
    ui->calendarWidget_2->move(257,83);
}
DCalendarDialog::~DCalendarDialog()
{
    delete ui;
}
