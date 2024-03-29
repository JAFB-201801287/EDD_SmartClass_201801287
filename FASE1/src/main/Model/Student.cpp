#include "Student.h"
//Carnet,DPI,Nombre,Carrera,Password,Creditos,Edad,Correo
// CONSTRUCTOR VACIO
Student::Student()
{
        this->carne = 0;
        this->dpi = "";
        this->name = "";
        this->career = "";
        this->password = "";
        this->credits = 0;
        this->age = 0;
        this->mail = "";
}

// CONSTRUCTOR CON PARAMENTROS
Student::Student(int carne, string dpi, string name, string career, string password, short int credits, short int age, string mail)
{
        this->carne = carne;
        this->dpi = dpi;
        this->name = name;
        this->career = career;
        this->password = password;
        this->credits = credits;
        this->age = age;
        this->mail = mail;
}

// DESTRUCTOR
Student::~Student() {}

// SETTERS ----------------------------------------------------------------------------------------------------------------------

void Student::setCarne(int carne) 
{
        this->carne = carne;
}

void Student::setDpi(string dpi) 
{
        this->dpi = dpi;
}

void Student::setName(string name) 
{
        this->name = name;
}

void Student::setCareer(string career) 
{
        this->career = career;
}

void Student::setPassword(string password) 
{
        this->password = password;
}

void Student::setCredits(short int credits) 
{
        this->credits = credits;
}

void Student::setAge(short int age) 
{
        this->age = age;
}

void Student::setMail(string mail) 
{
        this->mail = mail;
}

// GETTERS ----------------------------------------------------------------------------------------------------------------------

int Student::getCarne() 
{
        return this->carne;
}

string Student::getDpi() 
{
        return this->dpi;
}

string Student::getName() 
{
        return this->name;
}

string Student::getCareer() 
{
        return this->career;
}

string Student::getPassword() 
{
        return this->password;
}

short int Student::getCredits() 
{
        return this->credits;
}

short int Student::getAge() 
{
        return this->age;
}

string Student::getMail() 
{
        return this->mail;
}