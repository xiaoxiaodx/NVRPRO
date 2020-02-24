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

private:
    Ui::PasswordSetting *ui;
    void setControlPostion();
};

#endif // PASSWORDSETTING_H
