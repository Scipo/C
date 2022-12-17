#include <iostream>
using namespace std;

int main()
{
    int** arr = new int* [10];
    for(int i =0;i<10;i++){
         arr[i]=new int;
         *arr[i]=i;
    }
    for(int i =0;i<10;i++)
        cout<<*arr[i]<<" ";

    cout<<endl;
    
    for(int i=0;i<10;i++)
    {
        delete arr[i];
    }
    delete[] arr;
    return 0;
}
