//#include <QtGui>
#include <QApplication>
#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    main_window mw;
    mw.setGeometry(50,50,600,600);
    mw.show();

    return app.exec();
}
