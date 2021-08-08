#include <iostream>

#include "Model/Student.cpp"
#include "Model/Homework.cpp"
#include "Model/Error.cpp"

using namespace std;
//00
int main() 
{
    Student *student = new Student(201801287, "3007153150101", "Jose Andres Flores Barco", "Ingenieria En Ciencias y Sistemas", "1234", 10, 10);

    cout << "Carne: " << student->getCarne() << endl;
    cout << "DPI: " << student->getDpi() << endl;
    cout << "Nombre: " << student->getName() << endl;
    cout << "Carrera: " << student->getCareer() << endl;
    cout << "Password: " << student->getPassword() << endl;
    cout << "Creditos: " << student->getCredits() << endl;
    cout << "Edad: " << student->getAge() << endl;
    cout << endl;

    Homework *homework = new Homework(1, 201801287, "Tarea", "description", "matter", "date", "time_h", "state");
    
    cout << homework->getId() << endl;
    cout << homework->getCarne() << endl;
    cout << homework->getName() << endl;
    cout << homework->getDescription() << endl;
    cout << homework->getMatter() << endl;
    cout << homework->getDate() << endl;
    cout << homework->getTime_h() << endl;
    cout << homework->getState() << endl;
    cout << endl;

    Error *error = new Error(1, "Estudiante", "Correo mal escrito");

    cout << "ID: " << error->getId() << endl;
    cout << "TIPO: " << error->getType() << endl;
    cout << "DESCRIPCION: " << error->getDescrition() << endl;

    return 0;
}