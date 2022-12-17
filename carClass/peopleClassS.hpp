#include<iostream>
#include<assert.h>
#include<cstring>
using namespace std;
#include"peopleClass.hpp"

    People::People(char* nme,char*egn )
    {
        name= new char[strlen(nme)+1];
        assert(name!=NULL);
        strcpy(name,nme);
        unc = new char[strlen(egn)+1];
        assert(unc!=NULL);
        strcpy(unc,egn);
    }
    People::~People()
    {
        cout<<"~People()"<<endl;
        delete [] name;
        delete [] unc;
    }
    People::People(const People&r)
    {
          name= new char[strlen(r.name)+1];
          assert(name!=NULL);
          strcpy(name,r.name);
          unc = new char[strlen(r.unc)+1];
          assert(unc!=NULL);
          strcpy(unc,r.unc);
    }
    People& People::operator=(const People&r)
    {
        if(this!=&r)
        {
          delete [] name;
          delete [] unc;
          name= new char[strlen(r.name)+1];
          assert(name!=NULL);
          strcpy(name,r.name);
          unc = new char[strlen(r.unc)+1];
          assert(unc!=NULL);
          strcpy(unc,r.unc);
        }
        return *this;
    }
    
    void People::printPeople()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"EGN:  "<<unc<<endl;
    }