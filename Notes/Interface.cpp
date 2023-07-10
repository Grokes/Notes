#include "Interface.h"

void Interface::start()
{
    while (true)
    {
        cout << "Notes\n\n";
        cout << "1. Открыть файл с заметками\n";
        cout << "2. Создать новый файл\n";
        cout << "3. Выход\n";
        int choice;
        cin >> choice;
        cin.ignore();
        system("cls");
        switch (choice)
        {
        case 1: open_file(_old);
            break;
        case 2: open_file(_new);
            break;
        case 3: exit(0);
            break;
        default:
            break;
        }
    }
}

void Interface::open_file(int mode)
{
    bool (Notebook::*func)(std::string);
    (mode == _old) ? func = &Notebook::load : func = &Notebook::create;
    std::string path;
    cout << "Введите путь: ";
    std::getline(cin, path);
    if (!(notebook.*func)(path))
    {
        cout << "Операция не удалась\n";
        system("pause");
        system("cls");
    }
    else
    {
        system("cls");
        work_mode();
    }    
}

void Interface::create_note()
{
    std::string title;
    std::string body;
    cout << "Заголовок: ";
    getline(cin, title);
    cout << "Заметка: ";
    getline(cin, body);
    notebook.add(title, body);
    system("cls");
}

void Interface::save()
{
    char choice{};
    cout << "Сохранить?(y\\n)\n";
    cin >> choice;
    if (choice == 'y')
    {
        if (!notebook.save())
            cout << "Не удалось сохранить\n";
        else
            cout << "Успешно сохранено\n";
        system("pause");
    }
    system("cls");
}

void Interface::work_mode()
{
    while (true)
    {
        cout << "Notes\n";
        if (notebook.is_empty())
            cout << "Создайте вашу первую заметку!\n";
        else
            notebook.show();
        cout << endl;
        cout << "1. Добавить заметку\n";
        cout << "2. Режим просмотра заметок\n";
        cout << "3. Сохранить\n";
        cout << "4. Назад\n";
        cout << "5. Выход\n";
        char choice;
        cin >> choice;
        cin.ignore();
        system("cls");
        switch (choice)
        {
        case '1':
            create_note();
            break;
        case '2':
            view_mode();
            break;
        case '3':
            save();
            break;
        case '4':
            save();
            notebook.clear();
            return;
            break;
        case '5':
            save();
            exit(0);
            break;
        default:
            break;
        }
    }
}

void Interface::view_mode()
{
    if (notebook.is_empty())
    {
        cout << "Вы ещё не создали ни одной заметки!\n";
        system("pause");
        system("cls");
        return;
    }
    notebook.show();
    cout << endl;
    int num{};
    cout << "id заметки: ";
    cin >> num;
    cin.ignore();
    system("cls");
    read_note(notebook.find(num));
}

void Interface::read_note(list<pair<size_t, Note>>::iterator note)
{
    cout << note->second << "\n\n";
    cout << "1. Изменить\n";
    cout << "2. Удалить\n";
    cout << "3. Назад\n";
    int num{};
    cin >> num;
    cin.ignore();
    system("cls");
    switch (num)
    {
    case 1:
        edit_note(note);
        break;
    case 2:
        notebook.del(note);
        break;
    case 3:
        break;
    default:
        break;
    }
    system("cls");
}

void Interface::edit_note(list<pair<size_t, Note>>::iterator note)
{
    std::string title;
    std::string body;
    cout << "Заголовок: ";
    getline(cin, title);
    cout << "Заметка: ";
    getline(cin, body);
    note->second.edit(title, body);
    system("cls");
}