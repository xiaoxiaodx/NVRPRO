#ifndef PASSWORDSETTING_H
#define PASSWORDSETTING_H

#include <QDialog>

namespace Ui {
class PasswordSetting;
}

class PasswordSetting : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordSetting(QWidget *parent = NULL);
    ~PasswordSetting();

signals:
    void signal_password(QString,QString);
private slots:
    void on_pushButton_next_clicked();

private:

    Ui::PasswordSetting *ui;
    void setControlPostion();
};

#endif // PASSWORDSETTING_H
