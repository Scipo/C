#ifndef _CAR_HPP
#define _CAR_HPP

class Car
{
   private:
   char* brand;
   int year;
   int reg_number;

   public:
   Car();
   Car(char*,int, int);
   ~Car();
   Car& operator=(const Car&);
   void print_car();
};
#endif