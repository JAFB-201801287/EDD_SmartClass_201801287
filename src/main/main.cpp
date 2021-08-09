#include <iostream>
#include <fstream>

#include "Controller/StudentController.cpp"

using namespace std;
//0000
int main() 
{
    StudentController* controller = StudentController::getInstance();
    controller->print_student();
    cout << endl;
    controller->massive_charge();
    cout << endl;
    controller->print_student();
    cout << endl;
    controller->update_student("3502451230508", "201801287", "Jose Andres Flores Barco", "", "password1234", "", "", "");
    controller->delete_student("3423442386382");
    controller->print_student();
    cout << endl;

    return 0;
}