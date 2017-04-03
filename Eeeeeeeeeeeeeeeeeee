import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Window
{
    id :window
    visible: true
    width: 640
    height: 580
    title: qsTr("PHONE")
// main frame
    Loader
    {
        id: loader
        focus: true
    }

    Rectangle
    {
        id : root
        width : 640
        height : 480
        visible: true
        Image
        {
            id : background
            width : 640
            height: 480
            source : "qrc:/imagebackgroud/background.jpg"
            // phone
            Text
            {
                x:65
                y:300
                width: 131
                height: 41
                color: "black"
                text: 'Contacts'
                font.family: "Nirmala UI"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize :30
            }
            //music
            Text
            {
                x:231
                y:300
                color: "black"
                text: 'Music'
                font.family: "Nirmala UI"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize:30
            }
            Text
            {
                x:330
                y:300
                color: "black"
                text: 'Setting'
                font.family: "Nirmala UI"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize:30
            }
            Text
            {
                x:438
                y:300
                color: "black"
                text: 'Climate'
                wrapMode: Text.WordWrap
                font.family: "Nirmala UI"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize:30
            }
        }


        // Phonebook
        Image
        {
            id : phonebook
            x:80
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/phonebook.png"
            Loader
            {
                id: loaderPhonebook
                focus: true
            }
            MouseArea
            {
                id: areaPhonebook
                width : phonebook.width
                height: phonebook.height

                onClicked:
                {
                    loader.setSource("qrc:/phonebook.qml")
                   root.visible =! root.visible
//                    audio.visible =! audio.visible
//                    setting.visible =! setting.visible
//                    climate.visible =! climate.visible

                }

            }

        }

        // Audio
        Image
        {
            id: audio
            x: 200
            y: 180
            width : 100
            height : 100
            source: "qrc:/imagebackgroud/music.png"
            Loader
            {
                id: loaderImage
                focus: true
            }
            MouseArea
            {
                id:areaAudio
                width : setting.width
                height: setting.height
                anchors.fill: parent

                onClicked:
                {
                    loader.source = "qrc:/audio.qml"
                    root.visible =! root.visible
//                     phonebook.visible =! phonebook.visible
//                    setting.visible =! setting.visible
//                    climate.visible =! climate.visible
                }
            }
        }

        // Setting
        Image
        {
            id : setting
            x:320
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/setting.png"
            Loader
            {
                id: loaderSetting
                focus: true
            }

            MouseArea
            {
                id:areaSetting

                width : setting.width
                height: setting.height
                onClicked:
                {
                    loader.setSource("qrc:/setting.qml")
                    root.visible =! root.visible
//                    audio.visible =! audio.visible
//                    phonebook.visible =! phonebook.visible
//                    climate.visible =! climate.visible
                }
            }
        }
        //Climate
        Image
        {
            id : climate
            x:440
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/climate.png"
            Loader
            {
                id: loaderClimate
                focus: true
            }

            MouseArea
            {
                id:areaCimate
                width : setting.width
                height: setting.height
                onClicked:
                {
                    loader.setSource("qrc:/climate.qml")
                    root.visible =! root.visible
//                    audio.visible =! audio.visible
//                    phonebook.visible =! phonebook.visible
//                    setting.visible =!setting.visible
                }
            }

        }

    }
    // tool bar
    Rectangle
    {
        id: toolbar
        y:480
        width: 640
        height: 100
        Image {
            id: image
            source: "qrc:/imagebackgroud/index.jpg"
            width: toolbar.width
            height: toolbar.height
        }
        Label
        {
            id: clockLabel
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            font.pixelSize: 30
            Timer
            {
                id: clockTimer
                interval: 1000
                repeat: true
                running: visible
                onTriggered: clockLabel.text = Qt.formatDateTime(new(Date),"hh:mm:ss")
            }

        }

    }

}
