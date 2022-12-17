#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

#include "carPassport.hpp"

    CarPassport::CarPassport(char* brand, int year, int reg_mnum, char* name, char* egn): 
    Car(brand,year,reg_mnum),People(name, egn){}

    CarPassport::~CarPassport()
    {
         cout<<"~CarPassport()"<<endl;
    }
        
    CarPassport::CarPassport(const CarPassport&r):Car(r),People(r){}
    
    CarPassport& CarPassport::operator=(const CarPassport&cp)
    {
        if(this!=&cp)
        {
            Car::operator=(cp);
            People::operator=(cp);
        }
        return *this;
    }
    void CarPassport::print_carPassort()
    {
        print_car();
        printPeople();
    }