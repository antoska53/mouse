#include "widget.h"
#include <QApplication>
#include <QMouseEvent>
#include <QBitmap>
#include <QCursor>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
  //  QBitmap qbmp("super_spy.bmp");
    //QCursor qcurs1(qbmp, qbmp);
    //w.setCursor(qcurs1);
    w.setCursor(Qt::CrossCursor);

    w.show();



    return a.exec();
}
