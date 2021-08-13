#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>

#include "../Model/Student.cpp"
#include "../Lists/CircularDoubleLinkedList.cpp"


using namespace std;

class StudentController: public CircularDoubleLinkedList<Student>
{
    private:
        int id_report;
        static StudentController* instance;
        string* split(string);
        string replace(string);
        string remove_line_breaks(string);
        bool is_email_valid(string&);
    public:
        StudentController();
        ~StudentController();
        static StudentController* getInstance();

        Student find_student(string);
        bool find_student(int);

        void add_student(string, string, string, string, string, string, string, string);
        void add_student1(string);
        void update_student(string, string, string, string, string, string, string, string);
        void delete_student(string);
        void print_student();
        void massive_charge(string path);
        void report_student();
};

#endif