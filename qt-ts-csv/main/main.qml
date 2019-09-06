import QtQuick 2.0
import QtQuick.Window 2.11
import Qt.labs.platform 1.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Converter ") + version

    height: 300
    width: 380

    minimumHeight: 290
    minimumWidth: 300

    visible: ApplicationWindow.Windowed

    FileDialog {
        id: fileChooseInput
        title: "Source file"
        nameFilters: []
        folder:
            StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
        onAccepted: {
            showInputText.text = "source: " + conv.setSource(fileChooseInput.fileUrl)
            inputFormat.visible = true;
        }

    }

    FileDialog {
        id: folderChooseOutput
        selectFolder: true
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
            Layout.margins: 20

            RowLayout {

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
                        showInputText.text = "source: ";
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
            }

            RowLayout {
                id: showInput
                Text {
                    id: showInputText
                    Layout.fillWidth: true
                    text: "source: "
                }
            }
        }

        ColumnLayout {
            Layout.margins: 20
            RowLayout {
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
            }

            RowLayout {
                id: showOutput

                Text {
                    id: showOutputText
                    Layout.fillWidth: true
                    text: "destination: " + folderChooseOutput.folder
                }
            }
        }

        ColumnLayout {
            Layout.margins: 20
            RowLayout {
                id: conversion

                Button {
                    id: conversionBtnz
                    Layout.fillWidth: true
                    text: "Convert"
                    onClicked : {
                        conversionOutput.text = conv.convert()
                    }
                }
            }

            RowLayout {
                Text {
                    id: conversionOutput
                    Layout.fillWidth: true
                }
            }
        }
    }
}
