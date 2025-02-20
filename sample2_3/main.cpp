#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    qDebug()<<QT_VERSION_STR;
    return a.exec();
}
