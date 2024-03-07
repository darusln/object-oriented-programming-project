#pragma once
#include "Song.h"
#include "Repository.h"

class Action {
protected:
	Song s;
	Repository& repo;
public:
	Action(Repository& _repo, Song& _s) : repo(_repo), s(_s) {}
	virtual void undo() = 0;
	virtual void redo() = 0;
};

class ActionRemove : public Action {
public:
	ActionRemove(Repository& _repo, Song& _s) : Action(_repo, _s) {}
	void undo() {
		repo.store(s);
	}
	void redo() {
		repo.remove(s);
	}
};

class ActionAdd : public Action {
public:
	ActionAdd(Repository& _repo, Song& _s) : Action(_repo, _s) {}
	void undo() {
		repo.remove(s);
	}
	void redo() {
		repo.store(s);
	}
};

