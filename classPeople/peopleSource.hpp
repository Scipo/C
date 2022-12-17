#include "people.hpp"
#include <iostream>
#include <cassert>
#include<cstring>

void People::copy_People(char* na, char* uc)
{
    name = new char[strlen(na)+1];
    assert(name!=NULL);
    strcpy(name,na);
    ucn = new char[strlen(uc)+1];
    assert(ucn !=NULL);
    strcpy(ucn,uc);
}

void People::del_People()
{
    delete [] name; 
    delete [] ucn;
}

People::People(char* na, char* uc)
{
    copy_People(na,uc);
}
People::~People()
{
    del_People();
}
People::People(const People& p)
{
    copy_People(p.name,p.ucn);
}
People& People::operator=(const People&p)
{
    if(this!=&p)
    {
        del_People();
        copy_People(p.name,p.ucn);
    }
    return *this;
}
void People::printPeople()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"UCN: "<<ucn<<std::endl;
}
