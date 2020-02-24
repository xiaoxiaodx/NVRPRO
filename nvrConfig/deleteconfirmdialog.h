#ifndef DELETECONFIRMDIALOG_H
#define DELETECONFIRMDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteConfirmDialog;
}

class DeleteConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteConfirmDialog(QWidget *parent = NULL);
    ~DeleteConfirmDialog();

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::DeleteConfirmDialog *ui;
};

#endif // DELETECONFIRMDIALOG_H
