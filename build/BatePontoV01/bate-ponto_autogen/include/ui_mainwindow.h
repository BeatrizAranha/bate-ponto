/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelClock;
    QPushButton *btnRegistrar;
    QLabel *labelStatus;
    QTableWidget *tableRegistros;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(554, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelClock = new QLabel(centralwidget);
        labelClock->setObjectName("labelClock");
        labelClock->setGeometry(QRect(40, 30, 501, 64));
        QFont font;
        font.setPointSize(28);
        labelClock->setFont(font);
        btnRegistrar = new QPushButton(centralwidget);
        btnRegistrar->setObjectName("btnRegistrar");
        btnRegistrar->setGeometry(QRect(150, 120, 221, 51));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");
        labelStatus->setGeometry(QRect(10, 190, 521, 16));
        tableRegistros = new QTableWidget(centralwidget);
        if (tableRegistros->columnCount() < 3)
            tableRegistros->setColumnCount(3);
        tableRegistros->setObjectName("tableRegistros");
        tableRegistros->setGeometry(QRect(10, 220, 531, 321));
        tableRegistros->setColumnCount(3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 554, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelClock->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        btnRegistrar->setText(QCoreApplication::translate("MainWindow", "Registrar ponto", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Status: pronto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
