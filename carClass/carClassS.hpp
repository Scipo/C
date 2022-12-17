#include<iostream>
#include<cstring>
#include<assert.h>
using std::cout;
using std::cin;
using std::endl;

#include "carClass.hpp"

   Car::Car(char* nme,int m_year, int fr_number)
   {
       brand = new char[strlen(nme)+1];
       assert(brand!=NULL);
       strcpy(brand,nme);
       year=m_year;
       reg_number=fr_number;

   }
   Car::~Car()
   {
       cout<<"~Car()"<<endl;
       delete [] brand;
   }
   Car& Car::operator=(const Car& r)
   {
       if(this!=&r)
       {
           cout<<"Car&=";
           delete [] brand;
           brand = new char[strlen(r.brand)];
           assert(brand!=NULL);
           strcpy(brand,r.brand);
           year=r.year;
           reg_number=r.reg_number;
       }
    return *this;
   }
   void Car::print_car()
   {
       cout<<"Brand:      "<<brand<<endl;
       cout<<"Year:       "<<year<<endl;
       cout<<"Reg number: "<<reg_number<<endl;
   }