#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QObject* btn = new QPushButton;
    qDebug()<<btn->metaObject()->className();

    QPushButton* pushbtn = qobject_cast<QPushButton*>(btn);
    qDebug()<<pushbtn->metaObject()->className();

    QTimer* timer = new QTimer();
    qDebug()<<timer->inherits("QTimer");
    qDebug()<<timer->inherits("QObject");
    qDebug()<<timer->inherits("QPushButton");

    qDebug()<<btn->inherits("QPushButton");
    qDebug()<<btn->inherits("QAbstractButton");

    qDebug()<<btn->metaObject()->superClass()->className();
}
