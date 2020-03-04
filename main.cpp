#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    qDebug() <<"1:"<< qApp->font().rawName();
    qDebug() << qApp->font().family();
    qDebug() << qApp->font().defaultFamily();
    qDebug() << qApp->font().styleName();
    qDebug() << qApp->font().toString();
    qDebug() << qApp->font().key();

    QFont font;
    font.setFamily("helvetica");
    qApp->setFont(font);

    qDebug()  <<"2:"<< qApp->font().rawName();
    qDebug() << qApp->font().family();
    qDebug() << qApp->font().defaultFamily();
    qDebug() << qApp->font().styleName();
    qDebug() << qApp->font().toString();
    qDebug() << qApp->font().key();

    MainWindow w;

    w.showFullScreen();


    QFontDatabase SS;
    qDebug()<<"fonts:"<<SS.families();
    return a.exec();
}
