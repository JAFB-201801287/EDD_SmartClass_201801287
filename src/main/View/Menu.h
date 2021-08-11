#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "../Controller/StudentController.cpp"

using namespace std;

class Menu
{
    private:
        StudentController *studentController;

        void clear();
        string scanner();
        void stop();
        void print_info();
        void print_menu_options();
        void user_load();
    public:
        Menu();
        ~Menu();

        void view_menu();
        
};

#endif

#ifdef _WIN32
  #include<windows.h>
#endif 