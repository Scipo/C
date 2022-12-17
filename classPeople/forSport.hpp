#include"forScport.hpp"
#include <cstring>
void Sport::copy_sport(char* ne,char*st,double ag)
   {
      name = new char[strlen(ne)+1];
      strcpy(name,ne);
      sport = new char[strlen(st)+1];
      strcpy(sport,st);
      age=ag;
   }
   void Sport::del_sport()
   {
       delete [] name;
       delete [] sport;
   }
   Sport::Sport(char* name, char* sport, double age)
   {
       copy_sport(name,sport,age);
   }
   
   Sport::~Sport()
   {
       del_sport();
   }
   
   Sport& Sport::operator=(const Sport&r)
   {
       if(this != &r)
       {
           del_sport();
           copy_sport(r.name,r.sport,r.age);
       }
     return *this;
   }
   
   void Sport::printSport()
   {
      std::cout<<"Name: "<<name<<std::endl;
      std::cout<<"Sport: "<<sport<<std::endl;
      std::cout<<"Age: "<<age<<std::endl;  
   }
   
   