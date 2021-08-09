#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include <iostream>
#include <string>
#include <regex>

#include "../Model/Student.h"
#include "../Model/Student.cpp"
#include "../Lists/CircularDoubleLinkedList.cpp"
#include <sstream>

using namespace std;

class StudentController: public CircularDoubleLinkedList<Student>
{
    private:
        static StudentController* instance;
        string* split(string);
        string replace(string);
        bool is_email_valid(string&);
    public:
        StudentController();
        ~StudentController();
        static StudentController* getInstance();

        Student find_student(string);

        void add_student(string, string, string, string, string, string, string, string);
        void update_student(string, string, string, string, string, string, string, string);
        void delete_student(string);
        void print_student();
        void massive_charge();
};

#endif