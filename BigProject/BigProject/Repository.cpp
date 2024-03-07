#include "Repository.h"

void Repository::store(const Song& s) {
	Song o{ s };
	if (std::find(songs.begin(), songs.end(), s) != songs.end())
		throw SongException("A song " + o.getTitle() + " by " + o.getArtist() + " already exists");
	else
		songs.push_back(s);
}

const Song& Repository::find(string title, string artist) {
	vector<Song>::iterator it = std::find_if(songs.begin(), songs.end(), [&title, &artist](Song& s) {
		return (s.getTitle() == title && s.getArtist() == artist);
		});
	if (it == songs.end())
		throw SongException("The song " + title + " by " + artist + "does not exist");
	int index = std::distance(songs.begin(), it);
	return songs[index];
}

void Repository::remove(const Song& s) {
	Song o{ s };
	if (std::find(songs.begin(), songs.end(), s) == songs.end())
		throw SongException("The song " + o.getTitle() + " by " + o.getArtist() + " doesn't exist exists");
	else {
		auto del = std::remove(songs.begin(), songs.end(), s);
		songs.erase(del, songs.end());
	}
}
