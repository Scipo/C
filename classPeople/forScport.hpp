#ifndef _FOR_SOPRT_HPP
#define _FOR_SOPRT_HPP
#include<iostream>
class Sport
{
   private:
   char*  name;
   char* sport;
   double age;
   void copy_sport(char*,char*,double);
   void del_sport();
   public:
   Sport();
   Sport(char*, char*, double);
   ~Sport();
   Sport& operator=(const Sport&);
   void printSport();
};
//std::ostream& operator<<(ostream &os,const Sport&);
//std::istream& operator>>(istream &is,const Sport&);

#endif