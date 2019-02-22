TEMPLATE = subdirs

SUBDIRS = src

CONFIG(release, debug|release) {
    SUBDIRS += tests
}
