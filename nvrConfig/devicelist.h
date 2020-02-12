#ifndef DEVICELIST_H
#define DEVICELIST_H

#include <QWidget>

namespace Ui {
class DeviceList;
}

class DeviceList : public QWidget
{
    Q_OBJECT

public:
    explicit DeviceList(QWidget *parent = nullptr);
    ~DeviceList();

private:
    Ui::DeviceList *ui;

};

#endif // DEVICELIST_H
