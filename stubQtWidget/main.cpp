// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQtExamples/blob/master/LICENSE

#include "cvwidget.h"
#include <QApplication>
#include "../cvqt/share.h"

int main(int argc, char *argv[])
{
    CVQT_TIMESTAMP();

    QApplication a(argc, argv);

    CvWidget w;
    w.show();

    return a.exec();
}
