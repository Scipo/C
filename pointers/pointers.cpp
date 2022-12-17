#include<iostream>
using namespace std;
int main()
{
    int a;
    int *p;
    a=10;
    p=&a;
    cout<<a<<endl;
    cout<<"Address of P is: "<<p<<endl;
    *p=12;//dereference
    cout<<a<<endl;
    int b =20;
    *p = b;
    cout<<"Address of P is: "<<p<<endl;
    cout<<"Value of P: "<<*p<<endl;
    return 0;
}