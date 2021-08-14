#include "Error.h"

// CONSTRUCTOR VACIO
Error::Error()
{
        this->id = 0;
        this->type = "";
        this->description = "";
        this->id_homework = 0;
        this->dpi = "";
}

// CONSTRUCTOR CON PARAMENTROS
Error::Error(int id, string type, string description, int id_homework)
{
        this->id = id;
        this->type = type;
        this->description = description;
        this->id_homework = id_homework;
}

// DESTRUCTOR
Error::~Error() {}

// SETTERS ----------------------------------------------------------------------------------------------------------------------

void Error::setId(int id) 
{
        this->id = id;
}

void Error::setType(string type) 
{
        this->type = type;
}

void Error::setDescription(string description) 
{
        this->description = description;
}

void Error::setId_homework(int id_homework) 
{
        this->id_homework = id_homework;
}

void Error::setDpi(string dpi) 
{
        this->dpi = dpi;
}

// GETTERS ----------------------------------------------------------------------------------------------------------------------

int Error::getId() 
{
        return this->id;
}

string Error::getType() 
{
        return this->type;
}

string Error::getDescrition() 
{
        return this->description;
}

int Error::getId_homework() 
{
        return this->id_homework;
}

string Error::getDpi() 
{
        return this->dpi;
}

