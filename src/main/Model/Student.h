#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
    private:
        int carne;
        string dpi;
        string name;
        string career;
        string password;
        short int credits;
        short int age;

    public:
        Student();
        Student(int, string, string, string, string, short int, short int);
        ~Student();

        // SETTERS
        void setCarne(int);
        void setDpi(string);
        void setName(string);
        void setCareer(string);
        void setPassword(string);
        void setCredits(short int);
        void setAge(short int);

        // GETTERS
        int getCarne();
        string getDpi();
        string getName();
        string getCareer();
        string getPassword();
        short int getCredits();
        short int getAge();
};

#endif