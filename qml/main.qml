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

    TabView {
        id: mainTabView;
        anchors.fill: parent;
        anchors.margins: 10;

        UserManagementTab {
            id: userMgmtTab;
        }

        TransactionTab {
            id: transactionTab;
        }
    }

    UserController {
        id: userController;
    }

    UserModel {
        id: userModel;
    }
}
