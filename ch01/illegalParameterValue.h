#ifndef _ILLEGALPARAMETERVALUE_H
#define _ILLEGALPARAMETERVALUE_H

#include <iostream>
#include <string>

class illegalParameterValue
{
public:
    illegalParameterValue() : message("Illegal parameter value!!!") {}
    illegalParameterValue(char* theMessage) : { message = theMessage; }
    void outputMessage() { std::cout << message << std::endl; }
private:
    string message;
};


#endif
