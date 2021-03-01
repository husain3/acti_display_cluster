/*
 * Copyright (c) 2018 TOYOTA MOTOR CORPORATION
 * Copyright (C) 2016 The Qt Company Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import QtQuick 2.7
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
// that's for the 2nd option only
import io.qt.Backend 1.0

ApplicationWindow {
    id: root
    visible: true
    title: "ACTI Display Cluster"
    // and some silly resizing restrictions
    width: container.width * container.scale
    minimumWidth: 600
    height: container.height * container.scale
    minimumHeight: 800

    // that's for the 2nd option only
    Backend {
        id: backend
    }

    property double vehicleSpeed: 0
    property double engineSpeed: 0
    property double fuelFloat: 0


    // we can also connect to signals from C++ backend like this
    Connections {
        target: backend
        onDisplayData: {
//            rpmTxt.text = rpm;
//            console.log(rpm);
            vehicleSpeed = speed;
            engineSpeed = parseFloat(rpm);
            tachometer.value = engineSpeed / 7000;
            fuelFloat = parseInt(fuel);
            fuelLevel.value = fuelFloat / 100;
        }
    }

    Item {
        id: container
        anchors.centerIn: parent
        width: Window.width
        height: Window.height
        //scale: screenInfo.scale_factor()
        scale: 1

    Label {
        id: speed
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 20
        text: vehicleSpeed        /* MPH */
        font.pixelSize: 256
    }
    Label {
        id: unit
        anchors.left: speed.right
        anchors.baseline: speed.baseline
        text: 'Km/h'
        font.pixelSize: 64
    }

//    Text {
//        id: rpmTxt
////        anchors.horizontalCenter: parent.horizontalCenter
//        x: parent.width * 1 / 6
//        y: parent.height * 1 / 4
//        font.pointSize: 36
//        text: ""
//    }
    RowLayout {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 100

        ProgressBar {
            id: tachometer
            Layout.fillWidth: true
            value: engineSpeed / 65535
            Label {
                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.topMargin: 10
                text: '(RPM)'
                font.pixelSize: 26
            }
        }

        Item {
            width: 30
            height: 30
        }

        ProgressBar {
            id: fuelLevel
            Layout.fillWidth: true
            value: 0.66
            Image {
                anchors.left: parent.left
                anchors.leftMargin: -40
                anchors.bottom: parent.top
                source: './images/HMI_Dashboard_Fuel_Details.svg'
                GridLayout {
                    anchors.fill: parent
                    columns: 2
                    rowSpacing: -10
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 3
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignRight
                        text: 'LEVEL:'
                        font.pixelSize: 24
                    }
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 4
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignLeft
                        text: '%1 GALLONS'
                        font.pixelSize: 24
                        color: '#00ADDC'
                    }
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 3
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignRight
                        text: 'RANGE:'
                        font.pixelSize: 24
                    }
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 4
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignLeft
                        text: '%1 MI'
                        font.pixelSize: 24
                        color: '#00ADDC'
                    }
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 3
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignRight
                        text: 'AVG:'
                        font.pixelSize: 24
                    }
                    Label {
                        Layout.fillWidth: true
                        Layout.preferredWidth: 4
                        Layout.fillHeight: true
                        verticalAlignment: Label.AlignVCenter
                        horizontalAlignment: Label.AlignLeft
                        text: '%1 MPG'
                        font.pixelSize: 24
                        color: '#00ADDC'
                    }
                }
            }
            Label {
                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.topMargin: 10
                text: 'FUEL'
                font.pixelSize: 26
            }
        }
    }
  }
}
