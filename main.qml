import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import com.company.converter 1.0
import com.company.test 1.0
import QtQuick.Layouts 1.0

Window {
    id: rootId
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Converter {
        id: converterId
    }

    Rectangle {
        id: rect1
        width: parent.width
        height: parent.height / 1.5
        ListView {
            id: listViewId
            model: listId
            anchors.fill: parent
            delegate: RowLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                Rectangle {
                    id: nameRectId
                    x: 50
                    width: phoneRectId.width
                    height: nameId.implicitHeight + 10
                    anchors.left: parent.left
                    border.color: "black"
                    Text {
                        id: nameId
                        text: name
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: ageRectId
                    //width: parent.width / 3
                    height: ageId.implicitHeight + 10
                    width: ageId.implicitWidth + 10
                    anchors.horizontalCenter: parent.horizontalCenter
                    //anchors.left: nameRectId.right
                    border.color: "black"
                    Text {
                        id: ageId
                        text: age
                        anchors.centerIn: parent
                    }
                }
                Rectangle {
                    id: phoneRectId
                    //width: parent.width / 3
                    height: phoneId.implicitHeight + 10
                    width: phoneId.implicitWidth + 10
                    //anchors.left: ageRectId.right
                    border.color: "black"
                    Text {
                        id: phoneId
                        text: phone
                        anchors.centerIn: parent
                    }

                }
            }

        }
        ListModel {
            id: listId
        }
        Component.onCompleted: {
            var length = converterId.length();
            for(var i = 0; i < length; i++) {
                var list = converterId.getData(i)
                listId.append({"name":list[0],"age":list[1],"phone":list[2]})
            }
        }
    }
    Rectangle {
        width: parent.width
        height: parent.height - rect1.height
        color: "black"
        anchors.top: rect1.bottom
        Button {
            anchors.centerIn: parent
            text: "Update Data"
            onClicked:  {
                //converterId.writeJson(testId, "test.txt")
            }
        }
    }
}
