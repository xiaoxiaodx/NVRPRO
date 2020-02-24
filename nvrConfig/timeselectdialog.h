#ifndef TIMESELECTDIALOG_H
#define TIMESELECTDIALOG_H

#include <QDialog>
#include "util.h"
namespace Ui {
class TimeSelectDialog;
}

class TimeSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeSelectDialog(QWidget *parent = NULL);
    ~TimeSelectDialog();

    void setInitTime(QTime time);
    static QTime timeStr2QTime(QString str);
signals:
    void signal_timeChange(QTime time);
private slots:
    void on_listView_minute_clicked(const QModelIndex &index);

    void on_listView_seconds_clicked(const QModelIndex &indexes);

    void on_listView_hour_clicked(const QModelIndex &indexes);

    void on_pushButton_done_clicked();

    void on_pushButton_cancel_clicked();

private:


    Ui::TimeSelectDialog *ui;
    void init();
};

#endif // TIMESELECTDIALOG_H
