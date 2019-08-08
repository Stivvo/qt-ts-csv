TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
QT += quick

include($$PWD/qtxlsxwriter/src/xlsx/qtxlsx.pri)
include($$PWD/src.pri)

CONFIG(release, debug|release) {
    CONFIG += qtquickcompiler
    QMAKE_CXXFLAGS += -O3
}

CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += -O0
    QMAKE_CXXFLAGS -= -O1
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS -= -O3
    QMAKE_CXXFLAGS += --debug
}

SOURCES += $$PWD/main.cpp

RESOURCES += $$PWD/qml.qrc
