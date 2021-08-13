#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "../Controller/StudentController.cpp"
#include "../Controller/HomeworkController.cpp"

using namespace std;

class Menu
{
    private:
        StudentController *studentController;
        HomeworkController *homeworkController;
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
        void print_menu_update_student();
        void print_menu_update_homework();
        void menu_update();
        void user_load();
        void homework_load();
        void create_user();
        void remove_user(string);
        void create_homework();
        void view_update_homework();
        void remove_homework();
        void search_struct_homework();
        void search_position_homework();

        void view_manual_users();
        void view_manual_homeworks();
    public:
        Menu();
        ~Menu();

        void view_menu();
        
};

#endif

#ifdef _WIN32
  #include<windows.h>
#endif 