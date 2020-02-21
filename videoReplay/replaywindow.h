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
    explicit ReplayWindow(QWidget *parent = nullptr);
    ~ReplayWindow();
    void init();
signals:
    void signal_switchWindow(WindowType type);
protected:
    void mousePressEvent(QMouseEvent *event);

private:
    void createTimeLine();
    void popMenu();
    QPushButton *createSelfBtn(QString btnTxt,QString res);

    ReplayTimeline *replayTimeline=nullptr;
    MyCalendar *myCalendar = nullptr;
    Ui::ReplayWindow *ui;
};

#endif // REPLAYWINDOW_H
