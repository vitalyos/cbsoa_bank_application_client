TEMPLATE = app

QT += qml quick widgets network
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include(model/model.pri)
include(rest_client/rest.pri)
