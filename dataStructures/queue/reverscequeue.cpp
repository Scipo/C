#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printQueue(queue<int>&Queue)
{
    cout<<"Prining Queue: "<<endl;
    while(!Queue.empty())
    {
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
    cout<<endl;
}

void queueReverse(queue<int>&Queue)
{
    stack<int>stc;
    while(!Queue.empty())
    {
        stc.push(Queue.front());
        Queue.pop();   
    }   
    while(!stc.empty())
    {
        Queue.push(stc.top());
        stc.pop();
    }
}
void oddElements(queue<int>&Queue)
{
    queue<int>q;
    while(!Queue.empty())
    {
        if(Queue.front()&1)
            q.push(Queue.front());

         Queue.pop();   
    }
    while(!q.empty())
    {
        Queue.push(q.front());
        q.pop();
    } 
}

int main()
{
   queue<int>Q;
   for(int i=0;i<5;i++)
   {
       int x;
       cin>>x;
       Q.push(x);
   }

   oddElements(Q); 
   queueReverse(Q); 
   printQueue(Q);
   
   return 0;
}
