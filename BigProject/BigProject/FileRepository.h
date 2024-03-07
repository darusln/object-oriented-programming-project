#pragma once
#include "Repository.h"
#include <fstream>
#include <stdexcept>
using namespace std;

class RepositoryTest;
class FileRepoTest;

class FileRepository : public Repository {
public:
	friend class RepositoryTest;
	friend class FileRepoTest;
	FileRepository() : Repository(), filepath() {}
	FileRepository(string fp) : Repository(), filepath(fp) {}
	void setFilepath(string fp) { filepath = fp; }
	void load();
	void save();
	void store(const Song& s) override;
	void remove(const Song& s) override;
private:
	string filepath;
};

