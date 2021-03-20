#include "formword.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormWord w;
    w.show();
    return a.exec();
}
