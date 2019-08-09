include(x2x/x2x.pri)
include(convert/convert.pri)
include(read/read.pri)
include(write/write.pri)

#maybe i should just do that:
INCLUDEPATH += $$PWD/.
#includes would become longer but easier to understand
#and would force who uses them to learn
#how files are organized
