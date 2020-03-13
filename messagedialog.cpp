#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent,QString content) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);

    setAttribute(Qt::WA_TranslucentBackground, true);

    m_showContent = content;

    ui->label->setText(m_showContent);


}


void  MessageDialog::showDialogOnTop(QWidget *widget,int padding,int timeInterval )
{
    //文本显示的矩形大小
    QFont wordfont = QApplication::font();
    wordfont.setPointSize(12);
    QFontMetrics fm(wordfont);
    QRect rec = fm.boundingRect(m_showContent);


    QPoint controlGlobalPos = widget->mapToGlobal(QPoint(0,0));

    int dialogW = rec.width()+16;
    int dialogH = rec.height() +8;


    int dilogLeftX = controlGlobalPos.x() + (widget->width() - dialogW)/2 ;
    int dilogLeftY = controlGlobalPos.y() - dialogH - padding;


    QPoint screenPos(dilogLeftX,dilogLeftY);

    this->setGeometry(screenPos.x(),screenPos.y(),dialogW,dialogH);

    ui->label->setGeometry(0,0,dialogW,dialogH);

    this->show();

    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_destroySelf()));
    timer.start(timeInterval);

}


void  MessageDialog::showDialogOnBottom(QWidget *widget,int padding,int timeInterval )
{
    //文本显示的矩形大小
    QFont wordfont = QApplication::font();
    wordfont.setPointSize(12);
    QFontMetrics fm(wordfont);
    QRect rec = fm.boundingRect(m_showContent);


    QPoint controlGlobalPos = widget->mapToGlobal(QPoint(0,0));

    int dialogW = rec.width()+16;
    int dialogH = rec.height() +8;

    int dilogLeftX = controlGlobalPos.x() + (widget->width() - dialogW)/2 ;
    int dilogLeftY = controlGlobalPos.y() + dialogH + padding;

    QPoint screenPos(dilogLeftX,dilogLeftY);

    this->setGeometry(screenPos.x(),screenPos.y(),dialogW,dialogH);

    ui->label->setGeometry(0,0,dialogW,dialogH);

    this->show();

    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_destroySelf()));
    timer.start(timeInterval);
}

void MessageDialog::showDialogOnRight(QWidget *widget,int padding,int timeInterval )
{

    //文本显示的矩形大小
    QFont wordfont = QApplication::font();
    wordfont.setPointSize(10);
    QFontMetrics fm(wordfont);
    QRect rec = fm.boundingRect(m_showContent);

    QPoint controlGlobalPos = widget->mapToGlobal(QPoint(0,0));

    int dialogW = rec.width()+16;
    int dialogH = rec.height() +8;


    int dilogLeftX = controlGlobalPos.x() + widget->width() + padding;
    int dilogLeftY = controlGlobalPos.y() + (widget->height() - dialogH)/2;


    QPoint screenPos(dilogLeftX,dilogLeftY);

    this->setGeometry(screenPos.x(),screenPos.y(),dialogW,dialogH);

    ui->label->setGeometry(0,0,dialogW,dialogH);

    this->show();

    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_destroySelf()));
    timer.start(timeInterval);

}
void MessageDialog::showDialog(QPoint screenPos,int timeInterval)
{

    QFont wordfont = QApplication::font();
    wordfont.setPointSize(10);
    QFontMetrics fm(wordfont);
    QRect rec = fm.boundingRect(m_showContent);

    this->setGeometry(screenPos.x(),screenPos.y(),rec.width()+20,rec.height()+20);

    ui->label->setGeometry(0,0,this->width(),this->height());

    this->show();

    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_destroySelf()));
    timer.start(timeInterval);
}

void MessageDialog::slot_destroySelf()
{
    disconnect(&timer,SIGNAL(timeout()),this,SLOT(slot_destroySelf()));
    timer.stop();
    this->close();
    //deleteLater();
}
#include <QDebug>
MessageDialog::~MessageDialog()
{
    delete ui;
}
