#include "Notebook.h"

bool Notebook::save()
{
	file.open(path, std::ios::out | std::ios::binary);
	if (file.is_open())
	{
		for (auto& el : base)
		{
			//title
			size_t temp = el.second.title.size();
			file.write((char*)&temp, sizeof(size_t));
			file.write(el.second.title.c_str(), temp);
			//body
			temp = el.second.body.size();
			file.write((char*)&temp, sizeof(size_t));
			file.write(el.second.body.c_str(), temp);
		}
		file.close();
		return true;
	}
	return false;
}

bool Notebook::create(string path)
{
	file.open(path, std::ios::out | std::ios::binary);
	if (file.is_open())
	{
		this->path = path;
		file.close();
		return true;
	}
	return false;
}

bool Notebook::load(string path)
{
	file.open(path, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		this->path = path;
		char* title{};
		char* body{};
		size_t str_size{};
		while (true)
		{
			//title
			file.read((char*)&str_size, sizeof(size_t));
			title = new char[str_size+1] {};
			file.read(title, str_size);
			title += '\0';
			//body
			file.read((char*)&str_size, sizeof(size_t));
			body = new char[str_size+1] {};
			file.read(body, str_size);
			body += '\0';

			if (!file.eof())
			{
				add(title, body);
				delete[] title;
				delete[] body;
			}
			else 
			{
				delete[] title;
				delete[] body;
				break;
			}
		}
		file.close();
		return true;
	}
	return false;
}

void Notebook::show()
{
	for (auto& el : base)
		cout << el.first << ". " << el.second.title << endl;
}

void Notebook::add(string title, string body)
{
	Note temp(title, body);
	base.emplace_back(base.size() + 1, temp);
}
void Notebook::del(list<pair<size_t, Note>>::iterator iter)
{
	base.erase(iter);
	id_normalize();
}

void Notebook::id_normalize()
{
	size_t i{ 0 };
	for (auto& el : base)
		el.first = ++i;	
}
list<pair<size_t, Note>>::iterator Notebook::find(size_t id) 
{
	return find_if(begin(base), end(base), [=](auto& el) -> bool {return el.first == id; }); 
}

void Notebook::clear()
{
	path = "";
	base.clear();
}
Notebook::~Notebook()
{
	if (file.is_open())
		file.close();
}