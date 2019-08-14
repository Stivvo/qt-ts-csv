TEMPLATE = subdirs

SUBDIRS = src

CONFIG += c++17

CONFIG(debug, debug|release) {
    SUBDIRS += tests
    QMAKE_CXXFLAGS += -std=c++17
}
