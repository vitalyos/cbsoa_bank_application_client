import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

Tab {
    title: "Configuration";
    anchors.margins: 10;
    Layout.alignment: Qt.AlignTop;
    Layout.preferredWidth: 500;

    ColumnLayout {
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
