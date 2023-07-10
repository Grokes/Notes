#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Notebook.h"
using std::cout;
using std::cin;
using std::endl;

enum {_old = 0, _new = 1};
class Interface
{
private:
    Notebook notebook;

public:
    void start();
    void open_file(int mode);
    void work_mode();
    void view_mode();
    void read_note(list<pair<size_t, Note>>::iterator note);
    void edit_note(list<pair<size_t, Note>>::iterator note);
    void create_note();
    void save();
    
};

