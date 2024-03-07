#pragma once

#include <QtWidgets>
#include "ui_MainWindow.h"
#include "SongController.h"
#include "Playlist.h"
#include "FileRepository.h"
#include "SongFromFile.h"
#include <QtMultimedia>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class SongFromFile;
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* event) override;
    ~MainWindow();
public slots:
    void onAddSongPressed();
    void onRemoveSongPressed();
    void onSortTitlePressed();
    void onSortArtistPressed();
    void onViewLyricsPressed();
    void onCreatePlaylistPressed();
    void onAddFilePressed();
    void onWindowSignal();
    void onAddPlaylistPressed();
    void onRemovePlaylistPressed();
    void onPlaySongPressed();
private:
    Ui::MainWindowClass ui;
    FileRepository* songRepo;
    SongController* controller;
    Playlist* playlist;
    SongFromFile* w;

    
};
