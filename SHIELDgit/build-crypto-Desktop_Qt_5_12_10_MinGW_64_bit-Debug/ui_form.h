/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QListView *listView;
    QPushButton *pushButton;
    QListView *listView_2;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(939, 620);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listView = new QListView(Form);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(listView, 5, 0, 1, 1);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 2, 1, 1);

        listView_2 = new QListView(Form);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setMaximumSize(QSize(16777215, 200));

        gridLayout->addWidget(listView_2, 5, 1, 1, 1);

        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setPointSize(14);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 0, 5, 2);

        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(150, 30));
        lineEdit_2->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(lineEdit_2, 0, 2, 1, 1);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 30));
        lineEdit->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(lineEdit, 1, 2, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QApplication::translate("Form", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
