import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import edu.bbu.bank 1.0

ApplicationWindow {
    id: root;
    visible: true
    width: 1024
    height: 768
    title: "Bank Management Application"
    property int labelwidth: 120;
    property int fieldWidth: 180;

    signal configurationChanged (string addr, int port, string resource);
    signal userAdded (string username, string password, bool active);

    RowLayout {
        id: rows;
        anchors.fill: parent;
        anchors.margins: 10;
        ColumnLayout {
            Layout.alignment: Qt.AlignTop;
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
                anchors.bottomMargin: 30;
                onClicked: {
                    root.userAdded(fieldUsername.text,
                                   fieldPassword.text,
                                   cbActive.checked)
                }
            }

            ListView {
                id: usersList;
                model: userModel.users;
                Layout.preferredHeight: 550;
                Layout.preferredWidth: 300;
                focus: true;
                delegate: Component {
                    id: userDelegate;
                    Item {
                        id: delegateRoot;
                        height: 100;
                        ColumnLayout {
                            RowLayout {
                                Label {
                                    id: userIdLabel;
                                    text: "#" + model.modelData.userId;
                                    anchors.rightMargin: 10;
                                }
                                TextField {
                                    id: userNameInput;
                                    text: model.modelData.username;
                                    Layout.preferredWidth: 230;
                                }
                                CheckBox {
                                    id:activeCb;
                                    checked: model.modelData.active;
                                    text: "Active";
                                }
                            }

                            RowLayout {
                                TextField {
                                    id: passwordInput;
                                    text: model.modelData.password;
                                    Layout.preferredWidth: 240;
                                }
                                Button {
                                    id: updateBtn;
                                    text: "~";
                                    Layout.preferredWidth: 30;
                                }
                                Button {
                                    id: deleteBtn;
                                    text: "-";
                                    Layout.preferredWidth: 30;
                                }
                            }
                        }
                    }
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

    UserController {
        id: userController;
    }

    UserModel {
        id: userModel;
    }
}
