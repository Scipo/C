#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> sortStack(stack<int>&s)
{
    stack<int>tmp;
    while(!s.empty())
    {
        int tmps=s.top();
        s.pop();
        
        while(!tmp.empty()&&tmp.top()>tmps)
        {
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(tmps);
    }
  return tmp;
}
void printS(stack<int>&s)
{
    cout<<"Printing Sort stak!!!"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void reverce(stack<int>&s)
{
    queue<int>q;
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    } 

    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
   /* cout<<"Reverce!!!"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;*/
}

int main(int argc, char const *argv[])
{
    stack<int>s;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }   
    stack<int>tmp = sortStack(s);
    reverce(tmp);
    printS(tmp);
    return 0;
}

