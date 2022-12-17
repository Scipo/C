#include<iostream>
#include<stack>

using namespace std;

void deleteMidleminStack(stack<int>&s,int len,int curr = 0)
{
    if(s.empty()||curr==len)return;
       
    int x = s.top();
    s.pop();

    deleteMidleminStack(s,len,curr+1);
    
    if(curr!=len/2)
        s.push(x);
}
void printDeleteMid(stack<int>&s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
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
    deleteMidleminStack(s,s.size());
    printDeleteMid(s);
    return 0;
}

