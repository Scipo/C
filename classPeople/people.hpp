#ifndef _PEOPLE_HPP
#define _PEOPLE_HPP
class People
{
    private:
        char* name;
        char* ucn;
        //
        void copy_People(char*,char*);
        void del_People();        
    public:
        People(char*,char*);
        ~People();
        People(const People&);
        People& operator=(const People&);
        void printPeople();
};
#endif