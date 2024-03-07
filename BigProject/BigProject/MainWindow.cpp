#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
    songRepo = new FileRepository("songlibraray.txt");
    controller = new SongController(*songRepo);
    playlist = new Playlist();
    w =  new SongFromFile();

    connect(ui.addSong, &QPushButton::clicked, this, &MainWindow::onAddSongPressed);
    connect(ui.removeSong, &QPushButton::clicked, this, &MainWindow::onRemoveSongPressed);
    connect(ui.sortTitle, &QPushButton::clicked, this, &MainWindow::onSortTitlePressed);
    connect(ui.sortArtist, &QPushButton::clicked, this, &MainWindow::onSortArtistPressed);
    connect(ui.viewLyrics, &QPushButton::clicked, this, &MainWindow::onViewLyricsPressed);
    connect(ui.createPlaylist, &QPushButton::clicked, this, &MainWindow::onCreatePlaylistPressed);
    connect(ui.addFile, &QPushButton::clicked, this, &MainWindow::onAddFilePressed);
    connect(w, &SongFromFile::acceptButton, this, &MainWindow::onWindowSignal);
    connect(ui.addPlaylist, &QPushButton::clicked, this, &MainWindow::onAddPlaylistPressed);
    connect(ui.removePlaylist, &QPushButton::clicked, this, &MainWindow::onRemovePlaylistPressed);
    connect(ui.playSong, &QPushButton::clicked, this, &MainWindow::onPlaySongPressed);
    
}

void MainWindow::onAddSongPressed() {
    try {
        controller->addSong(ui.artistLine->text().toStdString(), ui.titleLine->text().toStdString(), ui.lyricsLine->toPlainText().toStdString(), ui.durationLine->text().toInt(), ui.linkLine->text().toStdString(), ui.yearLine->text().toInt());
        int time = ui.durationLine->text().toInt();
        QTime* timey{ new QTime{0, time / 60, time - time / 60 * 60, 0} };
        ui.songsList->addItem("\"" + ui.titleLine->text() + "\"" + " by " + ui.artistLine->text() + " - " + timey->toString("mm:ss"));
        statusBar()->showMessage("Song added.", 500);
    }
    catch (const SongException& e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
void MainWindow::onRemoveSongPressed() {
    try {
        //for (auto& s : songRepo->getSongs())
            //qDebug() << QString::fromStdString(s.getArtist()) << QString::fromStdString(s.getTitle());
        if (ui.songsList->count() != 0 && ui.songsList->selectedItems().size() != 0 ) {
            string demo = ui.songsList->currentItem()->text().toStdString();
            string title = demo.substr(1, demo.find_last_of("\"") - 1);
            string artist = demo.substr(demo.find_first_of(" ", demo.find_last_of("\"")) + 4, demo.size() - title.size() - 14);

            //qDebug() << QString::fromStdString(title) << " " << QString::fromStdString(artist);

            ui.songsList->takeItem(ui.songsList->currentIndex().row());
            controller->removeSong(artist, title);
            statusBar()->showMessage("Song removed.", 500);
        }
        else
            throw SongException("Select a song.");
    }
    catch (SongException e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
}

void MainWindow::onSortTitlePressed() {
    ui.songsList->clear();

    vector<Song> sorted_vec;

    if (ui.sortStyle->currentText() == "Ascending") 
        sorted_vec = controller->sortByTitle([](string a, string b) {return a <= b; });
    else if(ui.sortStyle->currentText() == "Descending")
        sorted_vec = controller->sortByTitle([](string a, string b) {return a >= b; });

    for (auto& s : sorted_vec) {
        QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
        ui.songsList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
    }

    statusBar()->showMessage("List sorted.", 500);
}
void MainWindow::onSortArtistPressed() {
    ui.songsList->clear();

    vector<Song> sorted_vec;

    if (ui.sortStyle->currentText() == "Ascending")
        sorted_vec = controller->sortByArtist([](string a, string b) {return a <= b; });
    else if (ui.sortStyle->currentText() == "Descending")
        sorted_vec = controller->sortByArtist([](string a, string b) {return a >= b; });

    for (auto& s : sorted_vec) {
        QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
        ui.songsList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
    }

    statusBar()->showMessage("List sorted.", 500);
}
void MainWindow::onViewLyricsPressed() {
    try {
        /*for (auto& s : songRepo->getSongs())
            qDebug() << QString::fromStdString(s.getArtist()) << QString::fromStdString(s.getTitle());*/
        if (ui.songsList->count() != 0 && ui.songsList->selectedItems().size() != 0) {
            string demo = ui.songsList->currentItem()->text().toStdString();
            string title = demo.substr(1, demo.find_last_of("\"") - 1);
            string artist = demo.substr(demo.find_first_of(" ", demo.find_last_of("\"")) + 4, demo.size() - title.size() - 14);
            Song s{ controller->searchSong(title, artist) };
            QMessageBox msgBox;
            msgBox.setWindowTitle("Lyrics");
            msgBox.setText(QString::fromStdString(s.getLyrics()));
            msgBox.exec();
        }
        else
            throw SongException("Select a song.");
    }
    catch (SongException e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
void MainWindow::onCreatePlaylistPressed() {
    ui.playList->clear();
    playlist->generateRandom(songRepo->getSongs());
    for (auto& s : playlist->getSongs()) {
        QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
        ui.playList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
    }
}
void MainWindow::onAddFilePressed() {
    w->show();
}
void MainWindow::onWindowSignal() {
    songRepo->setFilepath(w->getFilepath());
    try {
        songRepo->load();
    }
    catch (SongException e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
    for (auto& s : songRepo->getSongs()) {
        QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
        ui.songsList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
    }
}
void MainWindow::onAddPlaylistPressed() {
    try {
        if (ui.songsList->count() != 0 && ui.songsList->selectedItems().size() != 0) {
            string demo = ui.songsList->currentItem()->text().toStdString();
            string title = demo.substr(1, demo.find_last_of("\"") - 1);
            string artist = demo.substr(demo.find_first_of(" ", demo.find_last_of("\"")) + 4, demo.size() - title.size() - 14);
            Song s{ controller->searchSong(title, artist) };
            playlist->add(s);
            QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
            ui.playList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
        }
        else
            throw SongException("Select a song.");
    }
    catch (SongException e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
void MainWindow::onRemovePlaylistPressed() {
    try {
        if (ui.playList->count() != 0 && ui.playList->selectedItems().size() != 0) {
            string demo = ui.playList->currentItem()->text().toStdString();
            string title = demo.substr(1, demo.find_last_of("\"") - 1);
            string artist = demo.substr(demo.find_first_of(" ", demo.find_last_of("\"")) + 4, demo.size() - title.size() - 14);

            //qDebug() << QString::fromStdString(title) << " " << QString::fromStdString(artist);

            ui.playList->takeItem(ui.playList->currentIndex().row());
            playlist->remove(controller->searchSong(title, artist));
            statusBar()->showMessage("Song removed.", 500);
        }
        else
            throw SongException("Select a song.");
    }
    catch (SongException e) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Song Exception");
        msgBox.setText(e.what());
        msgBox.exec();
    }
}
void MainWindow::onPlaySongPressed() {
    
}
void MainWindow::keyPressEvent(QKeyEvent* event) {
    auto key = event->key();
    if (key == Qt::Key_Z && event->modifiers() == Qt::ControlModifier) {
        try{
            controller->undo();
            ui.songsList->clear();
            for (auto& s : songRepo->getSongs()) {
                QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
                ui.songsList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
            }
        }
        catch (SongException e) {
            statusBar()->showMessage(e.what(), 500);
        }
    }
    if (key == Qt::Key_Y && event->modifiers() == Qt::ControlModifier) {
        try {
            controller->redo();
            ui.songsList->clear();
            for (auto& s : songRepo->getSongs()) {
                QTime* time{ new QTime{0, s.getDuration() / 60, s.getDuration() - s.getDuration() / 60 * 60, 0} };
                ui.songsList->addItem("\"" + QString::fromStdString(s.getTitle()) + "\"" + " by " + QString::fromStdString(s.getArtist()) + " - " + time->toString("mm:ss"));
            }
        }
        catch (SongException e) {
            statusBar()->showMessage(e.what(), 500);
        }
    }
    
}
MainWindow::~MainWindow()
{}
