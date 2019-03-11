import QtQuick 2.0
import QtQuick.Window 2.11
import Qt.labs.platform 1.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    title: qsTr("Converter ") + version

    height: 400
    width: 400

    minimumHeight: 400
    minimumWidth: 350

    FileDialog {

        id: fileChooseInput
        title: "Source file"
        nameFilters: []
        folder:
            StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        onFileChanged: {
            showInputText.text = "source: " + conv.setSource(fileChooseInput.file)
            inputFormat.visible = true;
        }

    }

    FolderDialog {
        id: folderChooseOutput
        title: "Destination folder"
        folder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        onAccepted: {

            showOutputText.text = "destination: " + conv.setDest(folderChooseOutput.folder + qsTr("/output") +
                                                                 cb_Dest.currentText)
            cb_Dest.visible = true
        }
    }

    ColumnLayout {
        anchors.fill: parent

        ColumnLayout {
            Layout.margins: 30

            RowLayout { //selezione del file di input

                Button {
                    Layout.fillWidth: true
                    text: "Source file"
                    onClicked: fileChooseInput.open()
                    Layout.rightMargin: 15
                }

                ComboBox {
                    id: inputFormat
                    visible: true
                    Layout.fillWidth: true
                    model: [".ts", ".xlsx", ".csv"]
                    onCurrentIndexChanged: {
                        showInputText.text = "source: "
                        fileChooseInput.file = "";
                        switch(currentIndex)
                        {
                        case 0:
                            fileChooseInput.nameFilters = ["Linguist files (*.ts)"]
                            cb_Dest.model = [".csv", ".xlsx"]
                            break;
                        case 1:
                            fileChooseInput.nameFilters = ["Excel files (*.xlsx)"]
                            cb_Dest.model = [".csv", ".ts"]
                            break;
                        case 2:
                            fileChooseInput.nameFilters = ["Csv files (*.csv)"]
                            cb_Dest.model = [".ts ", ".xlsx"]
                            break;
                        }

                    }
                }
            } //end row Layout


            RowLayout { //visualizza il file selezionato in input
                id: showInput
                Text {
                    id: showInputText
                    Layout.fillWidth: true
                    text: "source: "
                    Layout.topMargin: 15
                }
            }
        }

        ColumnLayout {
            Layout.margins: 30
            RowLayout { //selezione file di output
                id: output

                Button {
                    Layout.fillWidth: true
                    text: "destination folder"
                    onClicked: folderChooseOutput.open()
                    Layout.rightMargin: 15
                }

                ComboBox {
                    id: cb_Dest
                    visible: true
                    Layout.fillWidth: true
                    model: []
                    onCurrentTextChanged: {
                        showOutputText.text = "destination: " + conv.setDest(folderChooseOutput.folder + qsTr("/output") +
                                                                             cb_Dest.currentText)
                    }
                }
            } // end file output

            RowLayout {  //visualizza file di output
                id: showOutput

                Text {
                    id: showOutputText
                    Layout.fillWidth: true
                    Layout.topMargin: 15
                    text: "destination: " + folderChooseOutput.folder
                }

            }
        }

        ColumnLayout {
            Layout.margins: 30
            RowLayout { //bottone
                id: conversion

                Button {
                    id: conversionBtnz
                    Layout.fillWidth: true
                    text: "Convert"
                    onClicked : {
                        conversionText.text = conv.convert()
                    }
                }
            }

            RowLayout {
                Text {
                    Layout.topMargin: 20
                    id: conversionText
                    Layout.fillWidth: true
                }
            }
        }
    } //end application layout
} //end ApplicationWindow
