#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using std::string;

class Note
{
private:
	string title;
	string body;

public:
	Note(string title = "title", string body = "body") :title{ title }, body{ body } {}

public:
	void edit(string title = "title", string body = "body");
	friend std::ostream& operator<< (std::ostream& out, const Note& note);
	friend class Notebook;
};



