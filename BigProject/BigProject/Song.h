#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "funct.h"

using namespace std;


class Song {
private:
	string artist;
	string title;
	string lyrics;
	int duration;
	string link;
	int year;
public:
	Song(string a, string t) : artist(a), title(t), lyrics(""), duration(0), link(""), year(0) {}
	Song(string a, string t, string ly, int d, string lk, int y) : artist(a), title(t), lyrics(ly), duration(d), link(lk), year(y) {}
	Song(const Song& o) : artist(o.artist), title(o.title), lyrics(o.lyrics), duration(o.duration), link(o.link), year(o.year) {}

	void setArtist(string a) { artist = a; }
	void setTitle(string t) { title = t; }
	void setDuartion(int d) { duration = d; }
	void setLink(string l) { link = l; }

	string getArtist() { return artist; }
	string getTitle() { return title; }
	string getLyrics() { return lyrics; }
	int getDuration() { return duration; }
	string getLink() { return link; }
	int getYear() { return year; }

	friend bool operator==(const Song& a, const Song& b);\
	friend bool operator!=(const Song& a, const Song& b);
};
