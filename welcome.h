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
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private:
    Ui::Welcome *ui;
    void setControlPostion();
};

#endif // WELCOM_H
