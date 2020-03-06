#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = nullptr,QString str="");
    ~ConfirmDialog();

    bool showDialog();

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::ConfirmDialog *ui;
    bool isYes = false;
};

#endif // CONFIRMDIALOG_H
