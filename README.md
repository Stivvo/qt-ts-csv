[![Build Status](https://travis-ci.org/guerinoni/qt-ts-csv.svg?branch=master)](https://travis-ci.org/guerinoni/qt-ts-csv)

# qt-ts-csv
A tool to generate csv and xlsx file from qt ts file and vice versa

## Build
I used qmake systems and QtCreator as IDE.  
* The build directory have to be on the same lavel as the repo one.
The source directory has to be namd "qt-ts-csv".
The build directoy has to be named "build-qt-ts-csv".  
* It's is required the usage of windeployqt (read below)

## Usage
## To generate output.csv  
![example conversion ts to csv](./doc/ts2csv.png)  
### To generate output.xlsx  
![example conversion ts to xlsx](./doc/ts2xlsx.png)  
### To generate output.ts  
![example conversion csv to ts](./doc/csv2ts.png)  
![example conversion xlsx to ts](./doc/xlsx2ts.png)
![example conversion xlsx to csv](./doc/csv2xlsx.png)
### How to use windeployqt  

qmldir must be the directory where there are qml files
```
your\path\to\your\qt\compiler\bin\windeployqt.exe --no-translations --qmldir=your\path\to\qt-ts-csv\src your\path\to\build-qt-ts-csv\src\release  
```
#### Example:  
```
C:\Qt\5.12.1\mingw73_64\bin\windeployqt.exe --no-translations --qmldir=C:\Users\prog1\Desktop\qt-ts-csv\src C:\Users\prog1\Desktop\build-qt-ts-csv\src\release  
```