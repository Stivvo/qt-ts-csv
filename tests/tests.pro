include(gtest_dependency.pri)

TEMPLATE = app
CONFIG -= app_bundle
CONFIG += console c++17 thread
LIBS += -lstdc++fs

INCLUDEPATH += $$PWD/../src

include($$PWD/../src/qtxlsxwriter/src/xlsx/qtxlsx.pri)
include($$PWD/../src/src.pri)

HEADERS += \
    $$PWD/Path.hpp \
    $$PWD/tst_ts_csv.hpp \
    $$PWD/tst_csv_ts.hpp \
    $$PWD/tst_ts_xlsx.hpp \
    $$PWD/tst_xlsx_ts.hpp \
    $$PWD/tst_xls_csv.hpp \
    $$PWD/tst_csv_xls.hpp

SOURCES += main.cpp

XLSX_NO_LIB
