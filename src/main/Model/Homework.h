#ifndef HOMEWORK_H
#define HOMEWORK_H

#include <iostream>
#include <string>

using namespace std;

class Homework
{
    private:
        int id;
        int carne;
        string name;
        string description;
        string matter;
        string date;
        string time_h;
        string state;

    public:
        Homework();
        Homework(int, int, string, string, string, string, string, string);
        ~Homework();

        // SETTERS
        void setId(int);
        void setCarne(int);
        void setName(string);
        void setDescription(string);
        void setMatter(string);
        void setDate(string);
        void setTime_h(string);
        void setState(string);

        // GETTERS
        int getId();
        int getCarne();
        string getName();
        string getDescription();
        string getMatter();
        string getDate();
        string getTime_h();
        string getState();
};

#endif