include($$PWD/../qt-ts-csv/3rdParty/3rdParty.pri)
include($$PWD/../qt-ts-csv/src.pri)
include($$PWD/catch/catch.pri)

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += c++1z console thread
LIBS += -lstdc++fs

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

HEADERS += $$PWD/TestHelper.hpp

SOURCES += \
    $$PWD/TestHelper.cpp \
    $$PWD/maincatch.cpp \
    $$PWD/tst_ts_csv.cpp \
    $$PWD/tst_csv_ts.cpp \
    $$PWD/tst_ts_xlsx.cpp \
    $$PWD/tst_xlsx_ts.cpp \
    $$PWD/tst_xlsx_csv.cpp \
    $$PWD/tst_csv_xlsx.cpp
