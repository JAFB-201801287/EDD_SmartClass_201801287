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
        bool cin_bool;

        void clear();
        string scanner();
        void stop();
        void print_info();
        void print_menu_options();
        void print_manual_options(string);
        void print_report_options();
        void print_menu_report();
        void print_menu_manual_options();
        void print_menu_manual();
        void print_menu_update();
        void menu_update();
        void user_load();
        void create_user();
        void remove_user(string);

        void view_manual_users();
    public:
        Menu();
        ~Menu();

        void view_menu();
        
};

#endif

#ifdef _WIN32
  #include<windows.h>
#endif 