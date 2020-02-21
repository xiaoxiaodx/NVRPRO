#ifndef CAMERAMENU_H
#define CAMERAMENU_H

#include <QDialog>

namespace Ui {
class CameraMenu;
}

class CameraMenu : public QDialog
{
    Q_OBJECT

public:
    explicit CameraMenu(QWidget *parent = nullptr);
    ~CameraMenu();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
private:
    Ui::CameraMenu *ui;
};

#endif // CAMERAMENU_H
