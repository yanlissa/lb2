#ifndef MAIN_EXCEPTION_H
#define MAIN_EXCEPTION_H

#include <iostream>

using namespace std;

class OutOfRangeException:public exception{
    const char *what() const throw(){
        return "Index is out of range";
    }
};

class IncompatibleDimException:public exception{
    const char *what() const throw(){
        return "Incompatible dimension";
    }
};

#endif //MAIN_EXCEPTION_H