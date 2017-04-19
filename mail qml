import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0
import QtQuick.Controls 2.0
import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Layouts 1.0
import QtQuick.Controls 1.0
import QtQuick.Dialogs 1.0
import QtMultimedia 5.0
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.1

import"script/weather.js" as Weather



Window
{
    id :window
    visible: true
    width: 640
    height: 580
    title: qsTr("Head Unit Simulator")

// Setting Rectangle
    Loader
    {
        id: loader
        focus: true
    }
    Rectangle
    {

        id: setting
        width: 640
        height: 480
        visible: false
        color : "orange"
        Image
        {
            width: setting.width
            height: setting.height
            source: "qrc:/imagebackgroud/index.jpg"
        }

    }

    // phonebook Rectangle
    Rectangle
    {

        id: phonebook
        width: 640
        height: 480
        visible: false
        color : "blue"
        Image
        {
            id: img
            width: phonebook.width
            height: phonebook.height
            source: "qrc:/imagebackgroud/index.jpg"
        }
       TabBar
        {
            id: tabBar
            TabButton
            {
                text: qsTr("Phone List")
            }
            TabButton
            {
                text: qsTr("Recent Call")
            }
            TabButton
            {
                text: qsTr("Favorite Phone Number")
            }

        }

    }

    // Audio Rectangle
    Rectangle
    {
        id: audio
        objectName: "item"
        width: 640
        height: 480
        visible: false
        color: "red"

        Image {

            width: audio.width
            height: audio.height
            source: "qrc:/imagebackgroud/index.jpg"
        }
        ColumnLayout
        {
            id: column
            objectName: "column"
            anchors.margins: 9
            anchors.fill: parent

            Label
            {
                id: infoLabel

                elide: Qt.ElideLeft
                verticalAlignment: Qt.AlignCenter
                Layout.minimumHeight: infoLabel.implicitHeight
                Layout.fillWidth: true
                Layout.fillHeight: true

            }
            RowLayout
            {
                id: row
                objectName: "row"
                spacing: 100
                anchors.margins: 20
                //previous
                ToolButton
                {

                }

                ToolButton
                {
                    id: playingButon
                    objectName: "playingButton"
                    visible: false
                    Layout.preferredWidth: previousButon.implicitHeight
                    iconSource: "qrc:/imageaudio/media-pause-32.png"
                    onClicked:
                    {
                       hMIEventController.HMIEvent("playing")
                        console.log("playingClicked")
                    }
                }

//play
                ToolButton
                {
                    id: playButton
                    objectName: "playButton"
                    Layout.preferredWidth: playButton.implicitHeight
                    iconSource: "qrc:/imageaudio/media-play-32.png"
                    visible: true
                    MouseArea
                    {
                        id: mouseArea
                        anchors.fill: parent
                        onClicked:
                        {
                           hMIEventController.HMIEvent("play")
                            console.log("playMusicClicked")
                        }
                    }
                    Connections
                    {
                        target: hMIEventController
                        onPlayed:
                        {

                            console.log("dang choi nhac ")
                            playingButon.visible =! playingButon.visible
                            playButton.visible=! playButton.visible
                        }
                    }
                }
//stop
                ToolButton
                {
                    id: stopButton
                     objectName: "stopButton"
                    Layout.preferredWidth: stopButton.implicitHeight
                    iconSource: "qrc:/imageaudio/media-stop-32.png"
                    onClicked:
                    {
                        hMIEventController.HMIEvent("stop")

                        console.log("StopMusicClicked")
//                        stopButton.visible =! stopButton.visible
                    }
                    Connections
                    {
                        target: hMIEventController
                        onStopped:
                        {
                            console.log("dang stop nhac ")
                          playingButon.visible =! playingButon.visible
                        }
                    }
                }
//next
                ToolButton
                {
                    id:nextButton
                    tooltip: qsTr("Next")
                    iconSource: "qrc:/imageaudio/next-32.png"
                    onClicked:
                    {
                        hMIEventController.HMIEvent("next")
                        console.log("nextClicked")
                    }
                    Connections
                    {
                        target: hMIEventController
                        onNexted:
                        {
                            console.log("dang next nhac ")
                          playingButon.visible =! playingButon.visible
                        }
                    }
                }



            }
            RowLayout
            {
                id: rowLayout2
                Slider
                {
                    id: positionSlider
                    Layout.minimumWidth: 75
                    Layout.fillWidth: true

                }
            }

            ColumnLayout
            {
                id: playlist

                ScrollView
                {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    flickableItem.interactive: true

                    ListView
                    {
                        id: playlistView
                        anchors.fill: parent
                        model: playlistModel
                        delegate: playlistDelegate
    //                    delegate: PlaylistDelegate {  }
                        highlight: playlistHighlight
                    }
                }
                RowLayout
                {
                    ToolButton
                    {
                        text: qsTr("Add music files")
                        iconSource: "qrc:/imageaudio/plus-32.png"
                        onClicked: addingMusicDialog.open()

                        FileDialog
                        {
                            id: addingMusicDialog
                            //folder : musicUrl
                            title: qsTr("Open audio files")
                            nameFilters: [qsTr("MP3 files (*.mp3)"), qsTr("All files (*.*)")]
                            selectMultiple: true
                            onAccepted:
                            {
                                var file_protocol = "file:///"
                                for (var i = 0; i < fileUrls.length; i++)
                                {
                                    var path = fileUrls[i].toString()
                                    path = path.substring(file_protocol.length, path.length)
                                    playlistModel.append( { "path" : path, } )
                                }
                            }
                        }
                    }

                }
                Component
                {
                    id: playlistDelegate

                    Item
                    {
                        width: parent.width
                        height: 30

                        Rectangle
                        {
                            id : rectItem
                            anchors.fill: parent
                            color: "#33000000"
                            radius: 5
                            visible: mouse.pressed
                        }

                        Text {
                            x: 10
                            y: 10
                            text: path
                        }

                        MouseArea
                        {
                            id: mouse
                            anchors.fill: parent
                            onClicked: playlistView.currentIndex = index
                            onDoubleClicked: mediaPlayer.source = path
                        }
                    }
                }
                Component
                {
                    id: playlistHighlight
                    Rectangle
                    {
                        color: "gray"
                        radius: 5
                        y: playlistView.currentItem.y
                        Behavior on y
                        {
                            SpringAnimation
                            {
                                spring: 3
                                damping: 0.2
                            }
                        }
                    }
                }
                ListModel
                {
                    id: playlistModel
                }
            }

        }

    }

    //Climate Rectangle
    Rectangle
    {
        id: climate
        width: 640
        height: 480
        visible: false
        color : "green"
        Image
        {
            width: climate.width
            height: climate.height
            source: "qrc:/imagebackgroud/index.jpg"
        }
        Component.onCompleted:
        {
            Weather.setCityName("Hanoi")
            Weather.parseJSON()
            Weather.parseJSON5Days()
        }
        SwipeView
        {
            id: swipeView
            currentIndex: 0
            anchors.fill: parent

            PageClimate
            {
                id: pageClimate
            }

        }

    }

    // Root Rectangle

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
            source : "qrc:/imagebackgroud/index.jpg"

            //Text icon
            // phone
            Text
            {
                x:65
                y:300
                width: 131
                height: 41
                color: "black"
                text: 'Phone'
                font.family: "Nirmala UI"
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize :30
            }
            //music
            Text
            {
                x:210
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

        //Icon Image
        // Phonebook
        Image
        {
            id : iphonebook
            x:80
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/call.png"
            MouseArea
            {
                id: areaPhonebook
                width : phonebook.width
                height: phonebook.height

                onClicked:
                {
                    phonebook.visible =! phonebook.visible
                   root.visible =! root.visible
                }

            }

        }

        // Audio
        Image
        {
            id: iaudio
            x: 200
            y: 180
            width : 100
            height : 100
            source: "qrc:/imagebackgroud/music.png"
            MouseArea
            {
                id:areaAudio
                anchors.fill: parent

                onClicked:
                {
                    audio.visible =! audio.visible
                    root.visible =! root.visible

                }
            }
        }

        // Setting
        Image
        {
            id : isetting
            x:320
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/setting.png"

            MouseArea
            {
                id:areaSetting
                anchors.fill: parent
                onClicked:
                {
                    setting.visible =! setting.visible
                    root.visible =! root.visible
                }

            }
        }
        //Climate
        Image
        {
            id : iclimate
            x:440
            y:180
            width : 100
            height : 100
            source : "qrc:/imagebackgroud/climate.png"

            MouseArea
            {
                id:areaCimate
                anchors.fill: parent
                onClicked:
                {
                    climate.visible =! climate.visible
                    root.visible =! root.visible

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
        // khu vuc date and time

        Label
        {
            id: clockLabel
            anchors.right: parent.right

            font.pixelSize: 32
            Timer
            {
                id: clockTimer
                interval: 1000
                repeat: true
                running: visible
                onTriggered: clockLabel.text = Qt.formatDateTime(new(Date),"hh:mm:ss")
            }
        }
        Text
            {
                id : date
               anchors.bottom: parent.bottom
               anchors.right: parent.right
                text: Qt.formatDateTime(new Date(), "dd/MM/yyyy")
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 23
            }
        ToolButton
        {
            id: homeButton
            iconSource: "qrc:/imagebackgroud/Home-96.png"
            onClicked:
            {
                loader.setSource("qrc:/main.qml")
                window.visible =! window.visible
            }
        }
        Label
        {


        }
    }

}
