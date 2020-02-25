#ifndef REPLAYWINDOW_H
#define REPLAYWINDOW_H

#include <QWidget>
#include "replaytimeline.h"
#include "mycalendar.h"
#include <QWidgetAction>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenu>
#include   "util.h"
namespace Ui {
class ReplayWindow;
}


class ReplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ReplayWindow(QWidget *parent = NULL);
    ~ReplayWindow();
    void init();

signals:
    void signal_switchWindow(WindowType type);
public slots:
    //菜单槽
    void slot_MasterClick();
    void slot_DeviceSetClick();
    void slot_SystemSetClick();

    void slot_popDateDialog();
    void slot_dateUpdate(QDate time);
protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void createTimeLine();
    void popMenu();
    QPushButton *createSelfBtn(QString btnTxt,QString res);

    ReplayTimeline *replayTimeline=NULL;
    MyCalendar *myCalendar = NULL;
    QMenu *buttonMenu = NULL;
    Ui::ReplayWindow *ui;
};

#endif // REPLAYWINDOW_H
