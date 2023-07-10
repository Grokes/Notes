#pragma once
#include "Note.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>

using std::for_each;
using std::find_if;
using std::list;
using std::fstream;
using std::pair;
using std::cin;
using std::cout;
using std::endl;


class Notebook
{
private:
	list<pair<size_t, Note>> base;
	fstream file;
	std::string path;

public:
	Notebook() = default;
	~Notebook();

public:
	bool is_empty() { return base.empty(); }
	bool save();
	bool create(string path);
	bool load(string path);
	void show();
	void add(string title, string body);
	list<pair<size_t, Note>>::iterator find(size_t id);
	void del(list<pair<size_t,Note>>::iterator iter);
	void clear();
private:
	void id_normalize();
};

