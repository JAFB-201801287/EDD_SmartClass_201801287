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

    public:
        Error();
        Error(int, string, string);
        ~Error();

        // SETTERS
        void setId(int);
        void setType(string);
        void setDescription(string);

        // GETTERS
        int getId();
        string getType();
        string getDescrition();
};

#endif