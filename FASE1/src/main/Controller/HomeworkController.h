#ifndef HOMEWORKCONTROLLER_H
#define HOMEWORKCONTROLLER_H

#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>
#include <ctime>

#include "../Model/Homework.cpp"
#include "../Lists/DoubleLinkedList.cpp"
#include "StudentController.h"

//#include "StudentController.cpp"


using namespace std;

class HomeworkController: public DoubleLinkedList<Homework>
{
    private:
        StudentController *studentController;
        ErrorController *errorController;
        int index;
        int id_report;
        int id_code;
        // FORMATO MES:DIA:HORA
        // MES: Julio [0]->7, Agosto [1]->8, Septiembre [2]->9, Octubre [3]->10, Noviembre [4]->11
        // DIA: [0-29] -> 1-30
        // HORA: [0-8] -> 8:00-16:00
        Homework *matriz[5][30][9];
        static HomeworkController* instance;
        string* split(string);
        string splitDate(string);
        string replace(string);
        void init_matriz();
    public:
        HomeworkController();
        ~HomeworkController();
        static HomeworkController* getInstance();

        Homework find_homework(string);

        void add_matriz(Homework,int,int,int);
        bool add_homework(Homework);
        void update_homework(string, string, string, string, string, string, string, string);
        void delete_homework(int,int,int);
        void print_homework();
        void massive_charge(string);
        void report_homework();
        bool find_homework(int);
        Homework find_homework1(int);
        Homework find_homework(int,int,int);
        bool position_homework(int,int,int);
        void update_homework(int, string, string, string, string, string);
        bool is_date_valid(string&);
        void generated_code();
};

#endif