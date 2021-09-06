#ifndef ERRORCONTROLLER_H
#define ERRORCONTROLLER_H

#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>

#include "../Model/Error.cpp"
#include "../Lists/LinkedList.cpp"


using namespace std;

class ErrorController: public LinkedList<Error>
{
    private:
        int id_report;
        int id_error;
        static ErrorController* instance;

    public:
        ErrorController();
        ~ErrorController();
        static ErrorController* getInstance();

        int getIndex();
        Error* getFirst();
        Error find_error(string);
        bool find_error(int);

        void add_error(string, string, int, string);
        void delete_error(int);
        void report_error();
};

#endif