#pragma once
#include <vector>
#include "Song.h"
#include <algorithm>
#include <random>

using namespace std;

class Playlist {
private:
	vector<Song> songs;
public:
	Playlist() : songs() {}
	vector<Song> getSongs() { return songs; }
	void add(Song s) {
		songs.push_back(s);
	}
	void remove(Song s) {
		auto del = std::remove(songs.begin(), songs.end(), s);
		songs.erase(del, songs.end());
	}
	void clear() {
		songs.clear();
	}
	void generateRandom(vector<Song> vs) {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(vs.begin(), vs.end(), g);
		songs = vs;
	}
};

