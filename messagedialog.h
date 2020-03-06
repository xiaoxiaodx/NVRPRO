#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class MessageDialog;
}

class MessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MessageDialog(QWidget *parent = nullptr,QString str="");
    ~MessageDialog();

    void showDialogOnRight(QWidget *widget,int padding = 20,int timeInterval = 1000 );
    void showDialogOnBottom(QWidget *widget,int padding= 20,int timeInterval  = 1000 );
    void showDialogOnTop(QWidget *widget,int padding= 20,int timeInterval = 1000  );
    void showDialog(QPoint screenPos,int timeInterval);
private slots:
    void slot_destroySelf();
private:
    Ui::MessageDialog *ui;
    QString m_showContent;
    QTimer timer;
};

#endif // MESSAGEDIALOG_H
