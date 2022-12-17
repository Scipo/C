#pragma once

class People
{
    private:
    char* name;
    char* unc;
    
    public:
    People(char*,char*);
    People(const People&);
    People& operator=(const People&);
    ~People();
    void printPeople();

};