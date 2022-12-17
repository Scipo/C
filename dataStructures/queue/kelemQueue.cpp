#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void kelem(int k, queue<int>&Queue)
{
    stack<int>stak;
    for(int i=0;i<k;i++)
    {
        stak.push(Queue.front());
        Queue.pop();
    }

    while(!stak.empty())
    {
        Queue.push(stak.top());
        stak.pop();
    }
    
    for(int i=0;i<Queue.size()-k;i++)
    {
        Queue.push(Queue.front());
        Queue.pop();
    }

}

void Print(queue<int>&Queue)
{
    while(!Queue.empty())
    {
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int>q;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    kelem(k,q);
    Print(q);
    return 0;
}