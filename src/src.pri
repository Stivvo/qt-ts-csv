INCLUDEPATH += \
    $$PWD/read/ \
    $$PWD/write/ \
    $$PWD/build/ \
    $$PWD/convert/ \
    $$PWD/x2x/

INCLUDEPATH += \
    $$PWD/../3rdParty/xml/rapidxml-1.13/ \
    $$PWD/../../3rdParty/xlsx/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/

#    $$PWD/../3rdParty/xlsx/OpenXLSX/ \
#    $$PWD/../3rdParty/xlsx/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/ \
include(x2x/x2x.pri)
include(convert/convert.pri)
include(read/read.pri)
include(write/write.pri)

#maybe i should just do that:
#INCLUDEPATH += $$PWD/.
#includes would become longer but easier to understand
#and would force who uses them to learn
#how files are organized
