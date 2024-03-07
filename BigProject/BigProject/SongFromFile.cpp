#include "SongFromFile.h"

SongFromFile::SongFromFile(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	connect(ui.acceptButton, &QPushButton::clicked, this, &SongFromFile::onAcceptButtonPressed);

}
void SongFromFile::onAcceptButtonPressed() {
	filepath = ui.fileLine->text().toStdString();
	this->close();
	emit acceptButton();
}
SongFromFile::~SongFromFile()
{}
