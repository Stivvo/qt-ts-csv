#include "Converter.hpp"
#include "Version.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtDebug>
#include <iostream>

int main(int argc, char **argv)
{
    //    cli run config
    //    --cli /home/stefano/prog/qt-ts-csv/tests/files/csv_ts/t1.ts
    //    /home/stefano/Desktop/output.csv

    Converter c;

    if (argc > 1) {
        std::string arg1(argv[1]);
        if (arg1 != "--cli")
            return 1;

        if (argc != 4) {
            std::cout << argc - 1 << " arguments, expected 3" << std::endl;
            return 2;
        }
        std::string source(argv[2]);
        std::string dest(argv[3]);

        std::cout << "input: " << source << std::endl;
        std::cout << "output: " << dest << std::endl;

        c.setSource(source);
        c.setDest(dest);

        std::string convOutput = c.convert().toStdString();
        std::cout << convOutput << std::endl;
        return 0;
    } else {
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QGuiApplication app(argc, argv);

        QQmlApplicationEngine engine;

        engine.rootContext()->setContextProperty(QStringLiteral("conv"), &c);

        const auto str_ver = Version::current().as_string();
        engine.rootContext()->setContextProperty(
            QStringLiteral("version"), QString::fromStdString(str_ver));

        engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
        if (engine.rootObjects().isEmpty()) {
            return -1;
        }

        return QGuiApplication::exec();
    }
}
