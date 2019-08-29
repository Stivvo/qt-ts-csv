include($$PWD/../src/3rdParty/3rdParty.pri)
include($$PWD/../src/src.pri)
include($$PWD/catch/catch.pri)

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += c++1z console thread
LIBS += -lstdc++fs

SUBDIRS += tests

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
