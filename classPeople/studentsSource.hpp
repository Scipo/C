#include<cstring>
#include<cassert>
#include<iostream>

#include "student.hpp"

void Students::copy_Students(double gp, char* f_nu, char* add)
{
    gpa = gp;
    fac_number=new char[strlen(f_nu)+1];
    assert(fac_number!=NULL);
    strcpy(fac_number,f_nu);
    addr = new char[strlen(add)+1];
    assert(addr!=NULL);
    strcpy(addr,add);
}
void Students::del_Students()
{
    delete [] fac_number;
    delete [] addr;
}
Students::Students(char* na, char* uc, double gp, char* f_nu, char* add):People(na,uc)
{
    copy_Students(gp,f_nu,add);
}
Students::~Students()
{
    del_Students();
}
Students::Students(const Students& s):People(s)
{
  copy_Students(s.gpa,s.fac_number,s.addr);
}
Students& Students::operator=(const Students&st){
    if(this!=&st)
    {
        People::operator=(st);
        del_Students();
        copy_Students(st.gpa,st.fac_number,st.addr);
    }
    return *this;
}
void Students::print_Students()
{
    printPeople();
    std::cout<<"GPA of Student: "<<gpa<<std::endl;
    std::cout<<"Faculcy Numbre: "<<fac_number<<std::endl;
    std::cout<<"Address: "<<addr<<std::endl;
}

