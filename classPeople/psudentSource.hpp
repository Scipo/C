#include<cassert>
#include<cstring>
#include <iostream>

#include "pstudet.hpp"
#include "student.hpp"

void PStudent::copy_PStudent(double fe,  char* empl)
{
    fee = fe;
    employment = new char[strlen(empl)+1];
    assert(employment!=NULL);
    strcpy(employment,empl);
}
void PStudent::del_PStudent()
{
    delete [] employment;
}

 PStudent::PStudent(char* na,char* uc,double gp, 
 char* f_nu, char* add,double fe,char* empl):Students(na,uc,gp,f_nu,add)
 {
     copy_PStudent(fe, empl);
 }

 PStudent::~PStudent()
 {
     del_PStudent();
 }
 PStudent::PStudent(const PStudent&r):Students(r)
 {
     copy_PStudent(r.fee,r.employment);
 }
PStudent& PStudent::operator=(const PStudent& r)
{
    if(this!=&r)
    {
       Students::operator=(r);
       del_PStudent();
       copy_PStudent(r.fee,r.employment);
    }
    return *this;
}
  
 void PStudent::PrintPStudent()
 {
    print_Students(); 
    std::cout<<"Fee: "<<fee<<std::endl;
    std::cout<<"Employmnet: "<<employment<<std::endl; 
 }
    
