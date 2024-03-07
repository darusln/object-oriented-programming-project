#include "SongController.h"

void SongController::addSong(string artist, string title, string lyrics = "", int duration = 0, string link = "", int year = 0) {
	Song s{ artist, title, lyrics, duration, link, year };
	if (artist == "" || title == "")
		throw SongException("The song requires a title and artist.");
	else {
		repo.store(s);
		undo_stack.push(new ActionAdd(repo, s));
	}
}
void SongController::removeSong(string artist, string title) {
	Song s{ repo.find(title, artist) };
	repo.remove(s);
	undo_stack.push(new ActionRemove(repo, s));
}

const Song& SongController::searchSong(string title, string artist) {
	return repo.find(title, artist);
}

vector<Song> SongController::sortByArtist(bool (rel)(string, string))
{
	vector<Song> vso = repo.getSongs();
	std::sort(vso.begin(), vso.end(), [rel](Song& a, Song& b) {
		return rel(a.getArtist(), b.getArtist());
		});
	return vso;
}

vector<Song> SongController::sortByTitle(bool (rel)(string, string))
{
	vector<Song> vso = repo.getSongs();
	std::sort(vso.begin(), vso.end(), [rel](Song& a, Song& b) {
		return rel(a.getTitle(), b.getTitle());
		});
	return vso;
}

void SongController::undo() {
	if (!undo_stack.empty()) {
		undo_stack.top()->undo();
		redo_stack.push(undo_stack.top());
		undo_stack.pop();
	}
	else
		throw SongException("There is no action to undo.");
}
void SongController::redo() {
	if (!redo_stack.empty()) {
		redo_stack.top()->redo();
		undo_stack.push(redo_stack.top());
		redo_stack.pop();
	}
	else
		throw SongException("There is no action to redo.");
}
SongController::~SongController() {
	while (!undo_stack.empty()) {
		delete undo_stack.top();
		undo_stack.pop();
	}
		

}
