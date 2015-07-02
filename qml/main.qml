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

        ListView {
            id: usersList;

            anchors.top: parent.bottom;
            anchors.bottom: parent.bottom;
            anchors.right: parent.right;

            model: userModel.users;

            delegate: Component {
                id: userDelegate;
                Item {
                    id: delegateRoot;
                    height: 200;
                    Label {
                        id: userIdLabel;
                        text: "#" + userId;
                        anchors.top: delegateRoot.top;
                        anchors.left: delegateRoot.left;
                    }
                    TextInput {
                        id: userNameInput;
                        text: username;
                        anchors.top: delegateRoot.top;
                        anchors.left: userIdLabel.right;
                    }
                    CheckBox {
                        id:activeCb;
                        checked: active;
                        text: "Active";
                        anchors.left: delegateRoot.left;
                        anchors.top: userNameInput.bottom;
                    }
                    TextInput {
                        id: passwordInput;
                        text: password;
                        anchors.top: userNameInput.bottom;
                        anchors.left: activeCb.right;
                        anchors.right: updateBtn.left;
                    }
                    Button {
                        id: updateBtn;
                        text: "~";
                        anchors.top: userNameInput.bottom;
                        anchors.right: deleteBtn.left;
                    }
                    Button {
                        id: deleteBtn;
                        text: "-";
                        anchors.top: userNameInput.bottom;
                        anchors.right: delegateRoot.left;
                    }
                }
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
