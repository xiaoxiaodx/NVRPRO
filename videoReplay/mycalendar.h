#ifndef MYCALENDAR_H
#define MYCALENDAR_H

#include <QDialog>
#include <QDate>
namespace Ui {
class MyCalendar;
}

class MyCalendar : public QDialog
{
    Q_OBJECT

public:
    explicit MyCalendar(QWidget *parent = nullptr);
    ~MyCalendar();

signals:
    void dateUpdate(QDate date);
private slots:
    void slot_currentPageChanged(int year, int month);
    void on_pushButton_yearnext_clicked();

    void on_pushButton_monthnext_clicked();

    void on_pushButton_monsepre_clicked();

    void on_pushButton_yearpre_clicked();

    void on_pushButton_done_clicked();

    void on_pushButton_cancel_clicked();

private:
    QString monthNumber2English(int month);
    Ui::MyCalendar *ui;
};

#endif // MYCALENDAR_H
