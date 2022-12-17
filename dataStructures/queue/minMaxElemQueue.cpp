#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    for(int i=0;i<3;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    int max = 0;
    while(!q.empty())
    {
      
      if(max<q.front())
            max=q.front();

        q.pop();
    }
    cout<<max<<endl;
    return 0;
}