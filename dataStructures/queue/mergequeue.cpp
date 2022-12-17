#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void queueMerge(queue<int>&Queue1,queue<int>&Queue2)
{
    queue<int>q;
    while(!Queue1.empty())
    {
        q.push(Queue1.front());
        Queue1.pop();
    }
    while(!Queue2.empty())
    {
        q.push(Queue2.front());
        Queue2.pop();
    }
    cout<<"C: "<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;   
}  


int main()
{
    queue<int>a;
    queue<int>b;
    cout<<"A: "<<endl;
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        a.push(x);
    }
    cout<<"B: "<<endl;
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        b.push(x);
    }
    queueMerge(a,b);
    return 0;
}