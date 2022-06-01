/********************************************************************************
** Form generated from reading UI file 'PrKeyPressEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRKEYPRESSEVENT_H
#define UI_PRKEYPRESSEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrKeyPressEventClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PrKeyPressEventClass)
    {
        if (PrKeyPressEventClass->objectName().isEmpty())
            PrKeyPressEventClass->setObjectName(QString::fromUtf8("PrKeyPressEventClass"));
        PrKeyPressEventClass->resize(600, 400);
        menuBar = new QMenuBar(PrKeyPressEventClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        PrKeyPressEventClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PrKeyPressEventClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PrKeyPressEventClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PrKeyPressEventClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PrKeyPressEventClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PrKeyPressEventClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PrKeyPressEventClass->setStatusBar(statusBar);

        retranslateUi(PrKeyPressEventClass);

        QMetaObject::connectSlotsByName(PrKeyPressEventClass);
    } // setupUi

    void retranslateUi(QMainWindow *PrKeyPressEventClass)
    {
        PrKeyPressEventClass->setWindowTitle(QCoreApplication::translate("PrKeyPressEventClass", "PrKeyPressEvent", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrKeyPressEventClass: public Ui_PrKeyPressEventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRKEYPRESSEVENT_H
