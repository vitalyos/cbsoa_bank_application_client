import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import edu.bbu.bank 1.0

ApplicationWindow {
   id: root;
   visible: true;
   width: 1024;
   height: 768;

   title: "Bank Management Application"
   property int labelwidth: 120;
   property int fieldWidth: 180;

   // user
   signal deleteUser (int id);
   signal refreshUserList ();
   signal createUser (UserDto user);
   signal updateUser (UserDto user);

   // transaction
   signal filterByIban (string iban);
   signal getAllOrderedByAmount ();
   signal performTransaction (TransactionDto aTrs);

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

         RowLayout {

            Button {
               id: btnUserAdd;
               text: "add user";
               enabled: false;
               anchors.bottomMargin: 30;

               UserDto {
                  id: creatingUser;
                  username: fieldUsername.text;
                  password: fieldPassword.text;
                  active: cbActive.checked;
               }

               onClicked: {
                  root.createUser (creatingUser);
               }
            }

            Button {
               id: refreshButton;
               text: "refresh";
               onClicked: {
                  root.refreshUserList ();
               }
            }

         }

         ListView {
            id: usersList;
            model: userModel.users;
            Layout.preferredHeight: 550;
            Layout.preferredWidth: 300;
            focus: true;
            clip: true;
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

                           UserDto {
                              id: updateDto;
                              userId:  model.modelData.userId;
                              password: passwordInput.text;
                              username:  userNameInput.text;
                              active: activeCb.checked;
                           }

                           onClicked: {
                              root.updateUser (updateDto);
                           }
                        }
                        Button {
                           id: deleteBtn;
                           text: "-";
                           Layout.preferredWidth: 30;
                           onClicked: {
                              root.deleteUser(model.modelData.userId);
                           }
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

      ColumnLayout {
         id: right;
         Layout.alignment: Qt.AlignTop;
         RowLayout {
            Label {
               text: "sourceAccount";
               Layout.preferredWidth: labelwidth;
            }
            TextField {
               Layout.preferredWidth: fieldWidth;
               id: fieldSrc;
            }
         }

         RowLayout {
            Label {
               text: "destaccount";
               Layout.preferredWidth: labelwidth;
            }
            TextField {
               Layout.preferredWidth: fieldWidth;
               id: fieldDest;
            }
         }

         RowLayout {
            Label {
               text: "amount";
               Layout.preferredWidth: labelwidth;
            }
            TextField {
               Layout.preferredWidth: fieldWidth;
               id: fieldAmount;
               validator: IntValidator {
                  id: amountValidator;
                  bottom: 1;
               }
            }
         }

         RowLayout {

            Button {
               id: btnPerformTrx;
               text: "perform";
               //                    enabled: false;
               anchors.bottomMargin: 30;

               TransactionDto {
                  id: creatingTrans;
                  sourceAccount: fieldSrc.text;
                  destAccount: fieldDest.text;
                  amount: parseInt(fieldAmount.text);
               }

               onClicked: {
                  root.performTransaction (creatingTrans);
               }
            }

            Button {
               id: refreshButtonTrList;
               text: "refresh";
               onClicked: {
                  root.getAllOrderedByAmount ();
               }
            }

         }

         RowLayout {
            Label {
               text: "filter";
               Layout.preferredWidth: labelwidth;
            }
            TextField {
               Layout.preferredWidth: fieldWidth;
               id: fieldfilter;
               onTextChanged: {
                  root.filterByIban (fieldfilter.text);
               }
            }
         }

         ListView {
            id: trxList;
            model: transactionModel.transactions;
            Layout.preferredHeight: 550;
            Layout.preferredWidth: 300;
            focus: true;
            clip: true;
            delegate: Component {
               ColumnLayout {
                  Label {
                     id: fromLabel;
                     text: "from: " + model.modelData.sourceAccount;
                  }
                  Label {
                     id: toLabel;
                     text: "to: " + model.modelData.destAccount;
                     visible: text.length > 4;
                  }
                  Label {
                     id: toExtAccount;
                     text: "to ext: " + model.modelData.destExternalAccount;
                     visible: !toLabel.visible;
                  }
                  Label {
                     id: amountLabel;
                     text: "amount: " + model.modelData.amount;
                  }
                  Label {
                     id: dateTimeLabel;
                     text: "dateTime: " + model.modelData.dateTime;
                  }
                  Label {
                     id: sep;
                     text: "---------------------------------------";
                  }
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

   TransactionModel {
      id: transactionModel;
   }

   TransactionController {
      id: transactionController;
   }

   Component.onCompleted: {
      // create user
      root.createUser.connect(userController.createUser);
      userController.requireCreateUser.connect(userModel.createUser);

      // refresh
      root.refreshUserList.connect(userController.refreshUserList);
      userController.requireRefreshUserList.connect(userModel.userListRequired);

      // update
      root.updateUser.connect(userController.updateUser);
      userController.requireUpdateUser.connect(userModel.updateUser);

      // delete user connections
      root.deleteUser.connect(userController.deleteUser);
      userController.requireDeleteUser.connect(userModel.deleteUser);

      // perfrom transaction
      root.performTransaction.connect(transactionModel.performTransaction);
      transactionController.requirePerformTransaction.connect (transactionModel.performTransaction);

      // get ordered by amount
      root.getAllOrderedByAmount.connect(transactionController.getAllOrderedbyAmount);
      transactionController.requireGetAllOrderedByAmont.connect(transactionModel.getAllOrderedByAmount);

      // get filtered after iban
      root.filterByIban.connect (transactionController.getAllFilteredByIban);
      transactionController.requireGetAllFilteredByIban.connect (transactionModel.getAllFilteredByIban);

      // refresh on startup
      root.refreshUserList ();
      root.getAllOrderedByAmount ();
   }
}
