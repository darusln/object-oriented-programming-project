#include "Song.h"

bool operator==(const Song& a, const Song& b) {
	return a.artist == b.artist && a.title == b.title;
}
bool operator!=(const Song& a, const Song& b) {
	return a.artist != b.artist && a.title != b.title;
}