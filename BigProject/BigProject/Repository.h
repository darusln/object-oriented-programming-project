#pragma once
#include <vector>
#include <iostream>
#include "Song.h"
#include <algorithm>
#include "SongException.h"
using namespace std;

class RepositoryTest;
class FileRepoTest;
class ControllerTest;

class Repository {
public:
	friend class RepositoryTest;
	friend class FileRepoTest;
	friend class ControllerTest;
	Repository() : songs() {}
	Repository(const Repository&) = delete;
	virtual void store(const Song& s);
	const Song& find(string title, string artist);
	virtual void remove(const Song& s);

	vector<Song>& getSongs() { return songs; }
protected:
	vector<Song> songs;
};

