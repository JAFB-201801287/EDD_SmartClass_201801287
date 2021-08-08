#include "Error.h"

// CONSTRUCTOR VACIO
Error::Error()
{
        this->id = 0;
        this->type = "";
        this->description = "";
}

// CONSTRUCTOR CON PARAMENTROS
Error::Error(int id, string type, string description)
{
        this->id = id;
        this->type = type;
        this->description = description;
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


