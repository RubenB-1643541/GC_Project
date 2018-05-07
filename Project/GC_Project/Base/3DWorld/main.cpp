#include "displaywindow.h"
#include <QApplication>
#include "datafilewriter.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    __3DWorld__::DisplayWindow w;
    w.show();

    return a.exec();

    //DataFileWriter write;
}
