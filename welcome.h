#ifndef WELCOM_H
#define WELCOM_H

#include <QDialog>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = NULL);
    ~Welcome();

signals:
    void signal_loginStr(QString);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Welcome *ui;
    void setControlPostion();
};

#endif // WELCOM_H
