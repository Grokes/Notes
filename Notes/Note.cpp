#include "Note.h"
void Note::edit(string title, string body)
{
	this->title = title;
	this->body = body;
}
std::ostream& operator<< (std::ostream& out, const Note& note)
{
	out << note.title << "\n";
	out << note.body;
	return out;
}

