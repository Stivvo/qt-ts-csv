TEMPLATE = subdirs
SUBDIRS = qt-ts-csv

CONFIG(debug, debug|release) {
    SUBDIRS += tests
}
