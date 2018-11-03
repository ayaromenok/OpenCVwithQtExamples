// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQtExamples/blob/master/LICENSE

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "../cvqt/share.h"
#include "qcvobject.h"


int main(int argc, char *argv[])
{
    CVQT_TIMESTAMP();
    qDebug() << QDateTime::currentMSecsSinceEpoch() << " msec since Epoch is\t"
             << QDateTime::currentDateTime();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");
    QQuickStyle::setFallbackStyle("Default");

    qmlRegisterType<QCvObject> ("CvObject", 1, 0, "CvObject");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
