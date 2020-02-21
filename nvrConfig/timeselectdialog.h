#ifndef TIMESELECTDIALOG_H
#define TIMESELECTDIALOG_H

#include <QDialog>

namespace Ui {
class TimeSelectDialog;
}

class TimeSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TimeSelectDialog(QWidget *parent = nullptr);
    ~TimeSelectDialog();

private:
    Ui::TimeSelectDialog *ui;
    void init();
};

#endif // TIMESELECTDIALOG_H
