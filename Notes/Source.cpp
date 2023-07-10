#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Interface.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Interface test;

    test.start();
    
    return 0;
}