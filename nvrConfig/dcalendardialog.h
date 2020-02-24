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

private:
    Ui::DCalendarDialog *ui;
};

#endif // DCALENDARDIALOG_H
