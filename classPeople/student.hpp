#ifndef _STUDENTS_HPP
#define _STUDENTS_HPP

#include "people.hpp"

class Students:public People
{
  private:
  double gpa;
  char* fac_number;
  char* addr;
  void copy_Students(double, char*,char*);
  void del_Students();

  public:
  Students(char*,char*,double, char*,char*);
  ~Students();
  Students(const Students&);
  Students& operator=(const Students &); 
    
  void print_Students();
};
#endif