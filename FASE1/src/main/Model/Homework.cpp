#include "Homework.h"

// CONSTRUCTOR VACIO
Homework::Homework()
{
    this->id = 0;
    this->month = 0;
    this->day = 0;
    this->hour = 0;
    this->carne = 0;
    this->name = "";
    this->description = "";
    this->matter = "";
    this->date = "";
    this->time_h = "";
    this->state = "";
}

// CONSTRUCTOR CON PARAMENTROS
Homework::Homework(int id, int carne, string name, string description, string matter, string date, string time_h, string state)
{
    this->id = id;
    this->carne = carne;
    this->name = name;
    this->description = description;
    this->matter = matter;
    this->date = date;
    this->time_h = time_h;
    this->state = state;
}

// DESTRUCTOR
Homework::~Homework() {}

// SETTERS ----------------------------------------------------------------------------------------------------------------------

void Homework::setId(int id) 
{
        this->id = id;
}

void Homework::setMonth(int month) 
{
        this->month = month;
}

void Homework::setDay(int day) 
{
        this->day = day;
}

void Homework::setHour(int hour) 
{
        this->hour = hour;
}

void Homework::setCarne(int carne) 
{
        this->carne = carne;
}

void Homework::setName(string name) 
{
        this->name = name;
}

void Homework::setDescription(string description) 
{
        this->description = description;
}

void Homework::setMatter(string matter) 
{
        this->matter = matter;
}

void Homework::setDate(string date) 
{
        this->date = date;
}

void Homework::setTime_h(string time_h) 
{
        this->time_h = time_h;
}

void Homework::setState(string state) 
{
        this->state = state;
}

// GETTERS ----------------------------------------------------------------------------------------------------------------------

int Homework::getId() 
{
        return this->id;
}

int Homework::getMonth() 
{
        return this->month;
}

int Homework::getDay() 
{
        return this->day;
}

int Homework::getHour() 
{
        return this->hour;
}

int Homework::getCarne() 
{
        return this->carne;
}

string Homework::getName() 
{
        return this->name;
}

string Homework::getDescription() 
{
        return this->description;
}

string Homework::getMatter() 
{
        return this->matter;
}

string Homework::getDate() 
{
        return this->date;
}

string Homework::getTime_h() 
{
        return this->time_h;
}

string Homework::getState() 
{
        return this->state;
}
