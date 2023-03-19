/********************************************************************************
** Form generated from reading UI file 'formencrypt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMENCRYPT_H
#define UI_FORMENCRYPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEncrypt
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QListView *listView_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormEncrypt)
    {
        if (FormEncrypt->objectName().isEmpty())
            FormEncrypt->setObjectName(QString::fromUtf8("FormEncrypt"));
        FormEncrypt->resize(800, 600);
        QFont font;
        font.setPointSize(14);
        FormEncrypt->setFont(font);
        centralwidget = new QWidget(FormEncrypt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 4, 2);

        listView_2 = new QListView(centralwidget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(listView_2, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 30));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(lineEdit_2, 1, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 7, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(lineEdit, 2, 2, 1, 1);

        FormEncrypt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormEncrypt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 31));
        FormEncrypt->setMenuBar(menubar);
        statusbar = new QStatusBar(FormEncrypt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FormEncrypt->setStatusBar(statusbar);

        retranslateUi(FormEncrypt);

        QMetaObject::connectSlotsByName(FormEncrypt);
    } // setupUi

    void retranslateUi(QMainWindow *FormEncrypt)
    {
        FormEncrypt->setWindowTitle(QApplication::translate("FormEncrypt", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("FormEncrypt", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormEncrypt: public Ui_FormEncrypt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMENCRYPT_H
