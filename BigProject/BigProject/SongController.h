#pragma once
#include "Repository.h"
#include "Action.h"
#include <stack>

class ControllerTest;

class SongController {
public:
	SongController(Repository& r) : repo(r) {}
	~SongController();
	friend class ControllerTest;
	void addSong(string artist, string title, string lyrics, int duration, string link, int year);
	void removeSong(string artist, string title);
	const Song& searchSong(string title, string artist);
	vector<Song> sortByArtist(bool (rel)(string, string));
	vector<Song> sortByTitle(bool (rel)(string, string));

	void undo();
	void redo();
private:
	Repository& repo;
	std::stack<Action*> undo_stack;
	std::stack<Action*> redo_stack;
};

