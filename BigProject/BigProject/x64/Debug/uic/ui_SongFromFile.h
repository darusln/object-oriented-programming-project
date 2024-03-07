/********************************************************************************
** Form generated from reading UI file 'SongFromFile.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGFROMFILE_H
#define UI_SONGFROMFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets>

QT_BEGIN_NAMESPACE

class Ui_SongFromFileClass
{
public:
    QWidget *centralWidget;
    QPushButton* acceptButton;
    QLineEdit* fileLine;

    void setupUi(QMainWindow *SongFromFileClass)
    {
        if (SongFromFileClass->objectName().isEmpty())
            SongFromFileClass->setObjectName("SongFromFileClass");
        //SongFromFileClass->resize(600, 400);
        centralWidget = new QWidget(SongFromFileClass);
        centralWidget->setObjectName("centralWidget");
        SongFromFileClass->setCentralWidget(centralWidget);

        QVBoxLayout* layout{ new QVBoxLayout{centralWidget} };
        layout->addWidget(new QLabel{ "Enter the text file:", centralWidget });
        fileLine = new QLineEdit{ centralWidget };
        layout->addWidget(fileLine);
        acceptButton = new QPushButton{ "Select file", centralWidget};
        layout->addWidget(acceptButton);

        retranslateUi(SongFromFileClass);

        QMetaObject::connectSlotsByName(SongFromFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *SongFromFileClass)
    {
        SongFromFileClass->setWindowTitle(QCoreApplication::translate("SongFromFileClass", "SongFromFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongFromFileClass: public Ui_SongFromFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGFROMFILE_H
