include($$PWD/../src/3rdParty/3rdParty.pri)
include($$PWD/../src/src.pri)
include($$PWD/catch/catch.pri)

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += console c++17 thread
LIBS += -lstdc++fs

SUBDIRS += tests
QMAKE_CXXFLAGS += -std=c++17
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -Wconversion

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

