#include "mainwindow.h"
#include <QApplication>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFont font;
    font.setFamily("Helvetica"); // Tahoma 宋体
    qApp->setFont(font);

    qDebug() << qApp->font().rawName();
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
