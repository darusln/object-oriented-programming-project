#pragma once
#include "FileRepository.h"
#include "SongController.h"
#include <assert.h>
#include "SongException.h"

class RepositoryTest {
public:
	static void testStore() {
		Repository repo;
		Song s1{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		repo.store(s1);
		assert(repo.getSongs()[0] == s1);
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		repo.store(s2);
		assert(repo.getSongs()[1] == s2);
		try {
			repo.store(Song{ "Adele", "Hello", "its me", 350, "yt.com", 2015 });
			assert(false);
		}
		catch(SongException){
			assert(true);
		}
	}
	static void testFind() {
		Repository repo;
		Song s1{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		repo.store(s1);
		assert(repo.getSongs()[0] == s1);
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		repo.store(s2);
		assert(repo.find("Hello", "Adele") == s1);
		assert(repo.find("Bye", "Adela") == s2);
		try {
			repo.find("Lady Gaga", "idk");
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
	}
	static void testRemove() {
		Repository repo;
		Song s1{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		repo.store(s1);
		assert(repo.getSongs()[0] == s1);
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		repo.store(s2);
		Song s3{ "Random", "Song", "no idea", 360, "yt.com", 2000 };
		repo.store(s3);
		repo.remove(s2);
		assert(repo.getSongs()[0] == s1);
		assert(repo.getSongs()[1] == s3);
		assert(repo.getSongs().size() == 2);
		repo.remove(s1);
		repo.remove(s3);
		assert(repo.getSongs().empty());
		try {
			repo.remove(s1);
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
	}
	static void runAll() {
		testStore();
		testFind();
		testRemove();
	}
};
class FileRepoTest {
public:
	static void testLoad() {
		FileRepository frepo{ "test1.txt" };
		frepo.load();
		Song s1{ "Jessica Simpson", "My Wonderful", "''A time when I was down and out\nNo lovin in my life", 300, "yt.com", 2000 };
		Song s2{ "John Lennon", "Just Because", "''Ah, remember this?\nWhy, I must have been thirteen when this came out!", 360, "yt.ro", 1980};
		Song s3{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		assert(frepo.getSongs()[0] == s1);
		assert(frepo.getSongs()[1] == s2);
		assert(frepo.getSongs()[2] == s3);
	}
	static void testSave() {
		FileRepository frepo{ "test2.txt" };
		Song s1{ "Jessica Simpson", "My Wonderful", "''A time when I was down and out\nNo lovin in my life", 300, "yt.com", 2000 };
		Song s2{ "John Lennon", "Just Because", "''Ah, remember this?\nWhy, I must have been thirteen when this came out!", 360, "yt.ro", 1980 };
		Song s3{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		frepo.store(s1);
		frepo.store(s2);
		frepo.store(s3);
		frepo.save();
		frepo.songs.clear();
		frepo.load();
		assert(frepo.getSongs()[0] == s1);
		assert(frepo.getSongs()[1] == s2);
		assert(frepo.getSongs()[2] == s3);
	}
	static void runAll() {
		testLoad();
		testSave();
	}
};
class ControllerTest {
public:
	static void testAddSong() {
		Repository repo;
		SongController cont{ SongController(repo) };
		Song s1{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		cont.addSong("Adele", "Hello", "its me", 350, "yt.com", 2015);
		assert(repo.songs[0] == s1);
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		cont.addSong("Adela", "Bye", "its you", 360, "yt.ro", 2020);
		assert(repo.songs[1] == s2);
		try {
			cont.addSong("Adela", "Bye", "its you", 360, "yt.ro", 2020);
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
	}
	static void testSearchSong() {
		Repository repo;
		SongController cont{ SongController(repo) };
		Song s1{ "Adele", "Hello", "its me", 350, "yt.com", 2015 };
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		Song s3{ "Random", "Song", "no idea", 360, "yt.com", 2000 };
		cont.addSong("Adele", "Hello", "its me", 350, "yt.com", 2015);
		cont.addSong("Adela", "Bye", "its you", 360, "yt.ro", 2020);
		cont.addSong("Random", "Song", "no idea", 360, "yt.com", 2000);
		assert(s1 == cont.searchSong("Hello", "Adele"));
		assert(s3 == cont.searchSong("Song", "Random"));
		try {
			cont.searchSong("Miau", "Miau");
			assert(false);
		}
		catch (SongException) {
			assert(true);
		}
		cout << "hey";
	}
	static void testRemoveSong() {
		Repository repo;
		SongController cont{ SongController(repo) };
		Song s2{ "Adela", "Bye", "its you", 360, "yt.ro", 2020 };
		Song s3{ "Random", "Song", "no idea", 360, "yt.com", 2000 };
		cont.addSong("Adele", "Hello", "its me", 350, "yt.com", 2015);
		cont.addSong("Adela", "Bye", "its you", 360, "yt.ro", 2020);
		cont.addSong("Random", "Song", "no idea", 360, "yt.com", 2000);
		cont.removeSong("Adele", "Hello");
		assert(repo.songs[0] == s2);
		assert(repo.songs[1] == s3);
		cont.removeSong("Random", "Song");
		assert(repo.songs[0] == s2);
		cont.removeSong("Adela", "Bye");
		assert(repo.songs.empty());
	}
	static void runAll() {
		testAddSong();
		testSearchSong();
		testRemoveSong();
	}
};
void TestAll() {
	RepositoryTest::runAll();
	FileRepoTest::runAll();
	ControllerTest::runAll();
}
