include($$PWD/../src/src.pri)
include($$PWD/catch/catch.pro)

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += console c++17 thread
LIBS += -lstdc++fs

INCLUDEPATH += \
    $$PWD/../src \
    $$PWD/catch/Catch2/include/

HEADERS += \
    $$PWD/Path.hpp \
    $$PWD/Debug.hpp \
    $$PWD/tst_ts_csv.hpp \
    $$PWD/tst_csv_ts.hpp \
    $$PWD/tst_ts_xlsx.hpp \
    $$PWD/tst_xlsx_ts.hpp \
    $$PWD/tst_xls_csv.hpp \
    $$PWD/tst_csv_xls.hpp

SOURCES += main.cpp

XLSX_NO_LIB
