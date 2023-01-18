QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../MLLP/src/Graph/graph_realisation.cpp \
    ../MLLP/src/Graph/layer.cpp \
    ../MLLP/src/Graph/neuron.cpp \
    ../MLLP/src/MLP.cpp \
    ../MLLP/src/Matrix/Matrix.cpp \
    ../MLLP/src/control/Control.cpp \
    form.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../MLLP/src/Graph/graph.h \
    ../MLLP/src/Graph/layer.h \
    ../MLLP/src/Graph/neuron.h \
    ../MLLP/src/MLP.hpp \
    ../MLLP/src/Matrix/Matrix.hpp \
    ../MLLP/src/control/Control.hpp \
    form.h \
    mainwindow.h

FORMS += \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    emnist-letters-test.csv \
    emnist-letters-train.csv \
    weights.w
