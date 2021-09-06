#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string>

using namespace std;

class Error
{
    private:
        int id;
        string type;
        string description;
        int id_homework;
        string dpi;

    public:
        Error();
        Error(int, string, string, int);
        ~Error();

        // SETTERS
        void setId(int);
        void setType(string);
        void setDescription(string);
        void setId_homework(int);
        void setDpi(string);

        // GETTERS
        int getId();
        string getType();
        string getDescrition();
        int getId_homework();
        string getDpi();
};

#endif