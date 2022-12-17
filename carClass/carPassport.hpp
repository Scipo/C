#pragma once

#include "carClass.hpp"
#include "peopleClass.hpp"

class CarPassport: public Car, public People
{
    public:
    CarPassport(char*, int, int, char*, char*);
    ~CarPassport();
    CarPassport(const CarPassport&);
    CarPassport& operator=(const CarPassport&);
    
    void print_carPassort();
};