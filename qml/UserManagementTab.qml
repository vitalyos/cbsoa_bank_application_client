import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Tab {
    id: userAddPanel;
    title: "User management";
    anchors.margins: 10;
    Layout.alignment: Qt.AlignTop;
    Layout.preferredWidth: 400;

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
