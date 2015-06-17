import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: root;
    visible: true
    width: 1024
    height: 768
    title: qsTr("Hello World")
    property int labelwidth: 150;
    property int fieldWidth: 250;

    signal configurationChanged (string addr, int port, string resource);

    TabView {
        anchors.fill: parent;
        anchors.margins: 10;
        Tab {
            title: "Configuration"
            anchors.margins: 10;

            ColumnLayout {
                spacing: 2;
                Layout.alignment: Qt.AlignTop;

                Binding {
                    target: btnSave;
                    property: "enabled";
                    value: true;
                    when: fieldPort.length > 0 &&
                          fieldServerAddr.length > 0 &&
                          fieldResource.length > 0;
                }

                RowLayout {
                    id: serveraddritem;
                    Label {
                        text: "server address";
                        Layout.preferredWidth: labelwidth;
                    }
                    TextField {
                        Layout.alignment: Qt.AlignRight;
                        Layout.preferredWidth: fieldWidth;
                        id: fieldServerAddr;
                    }
                }

                RowLayout {
                    Label {
                        text: "server port";
                        Layout.preferredWidth: labelwidth;
                    }
                    TextField {
                        Layout.preferredWidth: fieldWidth;
                        id: fieldPort;
                        validator: IntValidator {
                            top: 65535;
                            bottom: 0;
                        }
                    }
                }

                RowLayout {
                    Label {
                        text: "resource name";
                        Layout.preferredWidth: labelwidth;
                    }
                    TextField {
                        Layout.preferredWidth: fieldWidth;
                        id: fieldResource;
                    }
                }

                Button {
                    id: btnSave;
                    text: "save";
                    enabled: false;
                    onClicked: {
                        console.log("save btn click")
                        root.configurationChanged (fieldServerAddr.text,
                                                   fieldPort.text,
                                                   fieldResource.text)
                    }
                }

            }
        }

        Tab {
            title: "User management";
            Rectangle {
                color: "blue";
                width: 800;
                height: 600;
            }
        }

        Tab {
            title: "Transaction";
            Rectangle {
                color: "green";
                width: 800;
                height: 600;
            }
        }
    }
}
