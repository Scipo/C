#include<iostream>
using namespace std;
int main()
{
    int x = 5;
    int* p =&x;
    *p = 6;
    int** q=&p;
    int*** r = &q;

    cout<<*p<<endl;
    cout<<*q<<endl;
    cout<<*(*q)<<endl;
    cout<<*(*r)<<endl;
    cout<<*(*(*r))<<endl;
    ***r=10;
    cout<<"x= "<<x<<endl;
    **q = *p+2;
    cout<<"x= "<<x<<endl;
    return 0;
}