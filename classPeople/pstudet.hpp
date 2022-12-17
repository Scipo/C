#ifndef _PSTUDENT_HPP
#define _PSTUDENT_HPP

#include "student.hpp"

class PStudent:public Students
{
    private:
    double fee;
    char* employment;
    void copy_PStudent(double, char*);
    void del_PStudent(); 
   
    public:
    PStudent(char*,char*,double, char*, char*,double,char*);
    ~PStudent();
    PStudent(const PStudent&);
    PStudent& operator=(const PStudent&); 
    void PrintPStudent();
   
   
   
    

};
#endif