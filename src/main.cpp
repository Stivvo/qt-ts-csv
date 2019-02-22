#include "Converter.hpp"
#include "Version.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc,  char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Converter c;
    engine.rootContext()->setContextProperty(QStringLiteral("conv"), &c);

    const auto str_ver = Version::current().as_string();
    engine.rootContext()->setContextProperty(QStringLiteral("version"),
                                             QString::fromStdString(str_ver));

    engine.load(QUrl(QStringLiteral("qrc:Graphics.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return QGuiApplication::exec();
}
