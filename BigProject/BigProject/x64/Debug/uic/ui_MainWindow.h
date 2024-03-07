/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;

    QListWidget* songsList;
    QListWidget* playList;

    QLineEdit* titleLine;
    QLineEdit* artistLine;
    QLineEdit* durationLine;
    QLineEdit* yearLine;
    QLineEdit* linkLine;
    QTextEdit* lyricsLine;

    QPushButton* addSong;
    QPushButton* removeSong;
    QPushButton* viewLyrics;
    QPushButton* addFile;

    QComboBox* sortStyle;
    QPushButton* sortArtist;
    QPushButton* sortTitle;
    
    QPushButton* addPlaylist;
    QPushButton* removePlaylist;
    QPushButton* createPlaylist;
    QPushButton* playSong;
    //QPushButton* ;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(602, 424);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        MainWindowClass->setCentralWidget(centralWidget);
        
        QVBoxLayout* bigLayout{ new QVBoxLayout{centralWidget} };

        QHBoxLayout* upLayout{ new QHBoxLayout{centralWidget} };

        songsList = new QListWidget{ centralWidget };
        upLayout->addWidget(songsList);

        QVBoxLayout* upRightLayout{ new QVBoxLayout{centralWidget} };

        QFormLayout* songLayout{ new QFormLayout{centralWidget} };;

        titleLine = new QLineEdit{ centralWidget };
        songLayout->addRow("Title:", titleLine);
        artistLine = new QLineEdit{ centralWidget };
        songLayout->addRow("Artist:", artistLine);
        durationLine = new QLineEdit{ centralWidget };
        songLayout->addRow("Duration:", durationLine);
        yearLine = new QLineEdit{ centralWidget };
        songLayout->addRow("Year:", yearLine);
        linkLine = new QLineEdit{ centralWidget };
        songLayout->addRow("Link:", linkLine);
        lyricsLine = new QTextEdit{ centralWidget };
        songLayout->addRow("Lyrics:", lyricsLine);

        upRightLayout->addLayout(songLayout);

        QGridLayout* buttonLayout{ new QGridLayout{centralWidget} };

        addSong = new QPushButton{ "Add song" , centralWidget};
        buttonLayout->addWidget(addSong, 0, 0, 1, 2);
        removeSong = new QPushButton{ "Remove song", centralWidget };
        buttonLayout->addWidget(removeSong, 1, 0, 1, 2);
        viewLyrics = new QPushButton{ "View lyrics", centralWidget };
        buttonLayout->addWidget(viewLyrics, 2, 0, 1, 2);
        addFile = new QPushButton{ "Add songs from file(experimental)", centralWidget };
        buttonLayout->addWidget(addFile, 3, 0, 1, 2);
        buttonLayout->addWidget(new QLabel{ "Sorting style:", centralWidget }, 4, 0);
        sortStyle = new QComboBox{ centralWidget };
        sortStyle->addItem("Ascending");
        sortStyle->addItem("Descending");
        buttonLayout->addWidget(sortStyle, 4, 1);
        sortArtist = new QPushButton{ "Sort by artist", centralWidget };
        buttonLayout->addWidget(sortArtist, 5, 0);
        sortTitle = new QPushButton{ "Sort by title", centralWidget };
        buttonLayout->addWidget(sortTitle, 5, 1);

        upRightLayout->addLayout(buttonLayout);

        upLayout->addLayout(upRightLayout);

        bigLayout->addLayout(upLayout);

        QHBoxLayout* middleLayout{ new QHBoxLayout{centralWidget} };

        addPlaylist = new QPushButton{ "Add song to playlist", centralWidget };
        middleLayout->addWidget(addPlaylist);
        createPlaylist = new QPushButton{ "Generate random playlist", centralWidget };
        middleLayout->addWidget(createPlaylist);

        bigLayout->addLayout(middleLayout);

        QHBoxLayout* lowerLayout{ new QHBoxLayout{centralWidget} };

        playList = new QListWidget{ centralWidget };
        lowerLayout->addWidget(playList);

        QGridLayout* playButtonLayout{ new QGridLayout{centralWidget} };

        removePlaylist = new QPushButton{ "Remove song from playlist", centralWidget };
        playButtonLayout->addWidget(removePlaylist, 0, 0, 1, 2);
        //startPlay = new QPushButton{ "Remove song from playlist", centralWidget };
        //playButtonLayout->addWidget(removePlaylist, 0, 0, 1, 2);
        playSong = new QPushButton{ "Play song", centralWidget };
        playButtonLayout->addWidget(playSong, 1, 1);

        lowerLayout->addLayout(playButtonLayout);
        bigLayout->addLayout(lowerLayout);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
