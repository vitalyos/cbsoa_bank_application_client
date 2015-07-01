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

        ConfigurationTab {
            id: configTab;
        }

        UserManagementTab {
            id: userMgmtTab;
        }

        TransactionTab {
            id: transactionTab;
        }
    }
}
