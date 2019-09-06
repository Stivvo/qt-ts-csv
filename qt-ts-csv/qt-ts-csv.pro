TEMPLATE = app
CONFIG += c++1z
CONFIG -= app_bundle
QT += quick

include($$PWD/3rdParty/3rdParty.pri)
include($$PWD/src.pri)
include($$PWD/main/main.pri)

CONFIG(release, debug|release) {
    CONFIG += qtquickcompiler
    QMAKE_CXXFLAGS += -O3
}

CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += -O0
    QMAKE_CXXFLAGS -= -O1
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS -= -O3z
    QMAKE_CXXFLAGS += --debug
}
