#DISTFILES += \
#    $$PWD/OpenXLSX/@library/@openxlsx/CMakeLists.txt \
#    $$PWD/OpenXLSX/@library/@pugixml/CMakeLists.txt \
#    $$PWD/OpenXLSX/@library/@pugixml/LICENSE.md \
#    $$PWD/OpenXLSX/@library/@pugixml/README.md \
#    $$PWD/OpenXLSX/@library/@zippy/CMakeLists.txt \
#    $$PWD/OpenXLSX/@library/@zippy/LICENSE \
#    $$PWD/OpenXLSX/@library/@zippy/README.md \
#    $$PWD/OpenXLSX/@library/@zippy/Zippy/miniz/LICENSE \
#    $$PWD/OpenXLSX/@library/@zippy/Zippy/miniz/readme.md \
#    $$PWD/OpenXLSX/@library/CMakeLists.txt

HEADERS += \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLAbstractXMLFile_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLAppProperties_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellFormats_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellFormula_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellRange_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellReference_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellType_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCellValue_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCell_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLChartsheet_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLColor_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLColumn_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLContentTypes_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLCoreProperties_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLDocument_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLEnums_impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLFont_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLRelationships_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLRow_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLSharedStrings_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLSheet_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLStyles_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLTemplate_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLTokenizer_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLWorkbook_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLWorksheet_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/headers/XLXml_Impl.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/OpenXLSX.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLCell.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLCellRange.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLCellReference.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLCellValue.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLChartsheet.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLColumn.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLDefinitions.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLDocument.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLException.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLRow.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLSheet.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLWorkbook.h \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/headers/XLWorksheet.h \
    $$PWD/OpenXLSX/@library/@pugixml/pugiconfig.hpp \
    $$PWD/OpenXLSX/@library/@pugixml/pugixml.hpp \
    $$PWD/OpenXLSX/@library/@zippy/Zippy.h \
    $$PWD/OpenXLSX/@library/@zippy/Zippy/ZipArchive.h \
    $$PWD/OpenXLSX/@library/@zippy/Zippy/ZipEntry.h \
    $$PWD/OpenXLSX/@library/@zippy/Zippy/ZipException.h \
    $$PWD/OpenXLSX/@library/@zippy/Zippy/miniz/miniz.h \
    $$PWD/OpenXLSX/@tests/@catch/catch.hpp \
    $$PWD/OpenXLSX/@tests/@catch/catch_reporter_automake.hpp \
    $$PWD/OpenXLSX/@tests/@catch/catch_reporter_tap.hpp \
    $$PWD/OpenXLSX/@tests/@catch/catch_reporter_teamcity.hpp

SOURCES += \
    $$PWD/OpenXLSX/@examples/c++/Demo1.cpp \
    $$PWD/OpenXLSX/@examples/c++/Demo2.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLAbstractXMLFile_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLAppProperties_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCellFormats_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCellFormula_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCellRange_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCellReference_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCellValue_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCell_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLChartsheet_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLColor_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLColumn_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLContentTypes_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLCoreProperties_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLDocument_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLFont_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLRelationships_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLRow_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLSharedStrings_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLSheet_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLStyles_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLTokenizer_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLWorkbook_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/implementation/sources/XLWorksheet_Impl.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLCell.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLCellRange.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLCellReference.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLCellValue.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLChartsheet.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLColumn.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLDocument.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLRow.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLSheet.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLWorkbook.cpp \
    $$PWD/OpenXLSX/@library/@openxlsx/interfaces/c++/sources/XLWorksheet.cpp \
    $$PWD/OpenXLSX/@library/@pugixml/pugixml.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test00_Main.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test01_DocumentCreation.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test02_DocumentProperties.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test03_Workbook.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test04-06_Sheet.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test07_CellReference.cpp \
    $$PWD/OpenXLSX/@tests/c++/Test08_Cell.cpp

