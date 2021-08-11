#include <iostream>
#include <fstream>
//#include <string>

//#include "View/Menu.h"
#include "View/Menu.cpp"
//#include "Controller/StudentController.cpp"

using namespace std;
//000000
int main() 
{
    //StudentController* studentController = StudentController::getInstance();
    //string a;
    //getline(cin, a);
    //studentController->massive_charge(a);

    Menu menu;
    menu.view_menu();
    return 0;
}