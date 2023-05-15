/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>
#include "form.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Form *widget;
    QPushButton *pushButton;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QCustomPlot *widget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QFrame *line_2;
    QLabel *label_5;
    QFrame *line_3;
    QLabel *label_6;
    QFrame *line_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLabel *precision;
    QFrame *line_5;
    QLabel *accuracy;
    QFrame *line_6;
    QLabel *recall;
    QFrame *line_7;
    QLabel *fmeasure;
    QFrame *line_8;
    QLabel *time;
    QLabel *label_18;
    QCommandLinkButton *commandLinkButton;
    QPushButton *pushButton_3;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label_22;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_25;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label_23;
    QSlider *horizontalSlider_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(988, 669);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new Form(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 451, 361));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 390, 131, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Light")});
        font.setPointSize(12);
        font.setUnderline(true);
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 430, 271, 141));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tw Cen MT Condensed Extra Bold")});
        font1.setPointSize(36);
        label->setFont(font1);
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(340, 480, 89, 31));
        QFont font2;
        font2.setPointSize(10);
        radioButton->setFont(font2);
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(340, 520, 89, 20));
        radioButton_2->setFont(font2);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 520, 71, 31));
        widget_2 = new QCustomPlot(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(510, 20, 461, 321));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(530, 460, 441, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_5);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);
        label_6->setAutoFillBackground(false);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_6);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_7);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        precision = new QLabel(verticalLayoutWidget);
        precision->setObjectName(QString::fromUtf8("precision"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        precision->setFont(font3);
        precision->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(precision);

        line_5 = new QFrame(verticalLayoutWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        accuracy = new QLabel(verticalLayoutWidget);
        accuracy->setObjectName(QString::fromUtf8("accuracy"));
        accuracy->setFont(font3);
        accuracy->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(accuracy);

        line_6 = new QFrame(verticalLayoutWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        recall = new QLabel(verticalLayoutWidget);
        recall->setObjectName(QString::fromUtf8("recall"));
        recall->setFont(font3);
        recall->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(recall);

        line_7 = new QFrame(verticalLayoutWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_7);

        fmeasure = new QLabel(verticalLayoutWidget);
        fmeasure->setObjectName(QString::fromUtf8("fmeasure"));
        fmeasure->setFont(font3);
        fmeasure->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(fmeasure);

        line_8 = new QFrame(verticalLayoutWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_8);

        time = new QLabel(verticalLayoutWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setFont(font3);
        time->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(time);


        verticalLayout_2->addLayout(horizontalLayout);

        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(530, 360, 49, 16));
        commandLinkButton = new QCommandLinkButton(centralwidget);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(510, 350, 131, 51));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe UI")});
        font4.setPointSize(14);
        commandLinkButton->setFont(font4);
        commandLinkButton->setIconSize(QSize(30, 30));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(710, 370, 131, 41));
        pushButton_3->setFont(font);
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(510, 420, 471, 231));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        horizontalSlider = new QSlider(gridWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 2, 1, 1, 1);

        label_22 = new QLabel(gridWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 3, 0, 1, 1);

        horizontalSlider_2 = new QSlider(gridWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider_2->sizePolicy().hasHeightForWidth());
        horizontalSlider_2->setSizePolicy(sizePolicy);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 1, 1, 1, 1);

        horizontalSlider_3 = new QSlider(gridWidget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 3, 1, 1, 1);

        label_25 = new QLabel(gridWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout->addWidget(label_25, 4, 2, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_3 = new QRadioButton(gridWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setFont(font2);
        radioButton_3->setLayoutDirection(Qt::LeftToRight);
        radioButton_3->setChecked(true);

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(gridWidget);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy1);
        radioButton_4->setFont(font2);

        verticalLayout_3->addWidget(radioButton_4);


        gridLayout->addLayout(verticalLayout_3, 5, 2, 1, 1);

        label_23 = new QLabel(gridWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout->addWidget(label_23, 3, 2, 1, 1);

        horizontalSlider_4 = new QSlider(gridWidget);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_4, 4, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(60, -1, 60, -1);
        pushButton_4 = new QPushButton(gridWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(gridWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy2);
        pushButton_5->setMinimumSize(QSize(80, 10));

        verticalLayout->addWidget(pushButton_5);


        gridLayout->addLayout(verticalLayout, 5, 1, 1, 1);

        label_19 = new QLabel(gridWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 2, 2, 1, 1);

        label_20 = new QLabel(gridWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 1, 0, 1, 1);

        label_24 = new QLabel(gridWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout->addWidget(label_24, 4, 0, 1, 1);

        label_21 = new QLabel(gridWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 2, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        gridLayout->addLayout(verticalLayout_5, 5, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 988, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Recognize", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "This is ...", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "BMP File", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "precision", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "accuracy", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "recall", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", " f-measure", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "total time", nullptr));
        precision->setText(QCoreApplication::translate("MainWindow", "val", nullptr));
        accuracy->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        recall->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        fmeasure->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        time->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_18->setText(QString());
        commandLinkButton->setText(QCoreApplication::translate("MainWindow", "Test tool", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Run test", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Epoch", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Graph", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "Matrix", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Upload weight", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Download weight", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Layers", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Groups", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Part of sample", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
