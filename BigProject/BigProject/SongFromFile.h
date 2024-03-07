#pragma once

#include <QMainWindow>
#include "ui_SongFromFile.h"
#include <string>
#include "MainWindow.h"

class SongFromFile : public QMainWindow
{
	Q_OBJECT

public:
	SongFromFile(QWidget *parent = nullptr);
	std::string getFilepath() { return filepath; }
	~SongFromFile();
public slots:
	void onAcceptButtonPressed();
signals:
	void acceptButton();
private:
	Ui::SongFromFileClass ui;
	std::string filepath;
};
