#ifndef DCALENDARDIALOG_H
#define DCALENDARDIALOG_H

#include <QDialog>

namespace Ui {
class DCalendarDialog;
}

class DCalendarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DCalendarDialog(QWidget *parent = nullptr);
    ~DCalendarDialog();

    void init();
signals:
    void signal_dateUpdate(QString date1,QString date2);

private slots:
    void on_pushButton_done_clicked();
    void slot_currentPageChanged(int year, int month);
    void slot_currentPageChanged2(int year, int month);
    void on_pushButton_yearpre_clicked();

    void on_pushButton_monsepre_clicked();

    void on_pushButton_monthnext_clicked();

    void on_pushButton_yearnext_clicked();

    void on_pushButton_yearpre_2_clicked();

    void on_pushButton_monsepre_2_clicked();

    void on_pushButton_monthnext_2_clicked();

    void on_pushButton_yearnext_2_clicked();

private:
    QString monthNumber2English(int month);
    Ui::DCalendarDialog *ui;
};

#endif // DCALENDARDIALOG_H
