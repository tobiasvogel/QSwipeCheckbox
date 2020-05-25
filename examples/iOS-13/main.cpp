#include "screenexample.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/SF-Pro-Display-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/SF-Pro-Display-Semibold.ttf");

    ScreenExample w;
    w.show();
    return a.exec();
}
