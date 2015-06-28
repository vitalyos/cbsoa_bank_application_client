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
    signal userAdded (string username, string password, bool active);

    TabView {
        anchors.fill: parent;
        anchors.margins: 10;
        Tab {
            title: "Configuration"
            anchors.margins: 10;
            Layout.alignment: Qt.AlignTop;

            ColumnLayout {
                spacing: 2;
                Layout.alignment: Qt.AlignTop;

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

                Binding {
                    target: btnSave;
                    property: "enabled";
                    value: true;
                    when: fieldPort.length > 0 &&
                          fieldServerAddr.length > 0 &&
                          fieldResource.length > 0;
                }

                Binding {
                    target: btnSave;
                    property: "enabled";
                    value: false;
                    when: fieldPort.length == 0 ||
                          fieldServerAddr.length == 0 ||
                          fieldResource.length == 0;
                }

            }
        }

        Tab {
            title: "User management";
            anchors.margins: 10;
            Layout.alignment: Qt.AlignTop;
            RowLayout {
                Item {
                    id: userAddPanel;
                    Layout.preferredWidth: 500;
                    Layout.alignment: Qt.AlignTop;
                    ColumnLayout {
                        RowLayout {
                            Label {
                                text: "username";
                                Layout.preferredWidth: labelwidth;
                            }
                            TextField {
                                Layout.preferredWidth: fieldWidth;
                                id: fieldUsername;
                            }
                        }

                        RowLayout {
                            Label {
                                text: "password";
                                Layout.preferredWidth: labelwidth;
                            }
                            TextField {
                                Layout.preferredWidth: fieldWidth;
                                id: fieldPassword;
                                echoMode: TextInput.Password;
                            }
                        }

                        RowLayout {
                            Label {
                                text: "password again";
                                Layout.preferredWidth: labelwidth;
                            }
                            TextField {
                                Layout.preferredWidth: fieldWidth;
                                id: fieldPasswordAgain;
                                echoMode: TextInput.Password;
                            }
                        }

                        RowLayout {
                            Label {
                                text: "active";
                                Layout.preferredWidth: labelwidth;
                            }
                            CheckBox {
                                id: cbActive;
                            }
                        }

                        Button {
                            id: btnUserAdd;
                            text: "add user";
                            enabled: false;
                            onClicked: {
                                root.userAdded(fieldUsername.text,
                                               fieldPassword.text,
                                               cbActive.checked)
                            }
                        }

                        Binding {
                            target: btnUserAdd;
                            property: "enabled";
                            value: true;
                            when: fieldUsername.text.length > 0 &&
                                  fieldPassword.text.length > 0 &&
                                  fieldPassword.text == fieldPasswordAgain.text;
                        }

                        Binding {
                            target: btnUserAdd;
                            property: "enabled";
                            value: false;
                            when: fieldUsername.text.length == 0 ||
                                  fieldPassword.text.length == 0 ||
                                  fieldPassword.text != fieldPasswordAgain.text;
                        }

                    }
                }
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
