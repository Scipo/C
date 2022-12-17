#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int minIndex(queue<int>&q, int sortIndex)
{
    int min_index = - 1;
    int min_val = INT32_MAX;

    int n = q.size();

    for(int i=0;i<n;i++)
    {
        int curr = q.front();
        q.pop();
        if(curr<=min_val&&i<=sortIndex)
        {
            min_val = curr;
            min_index = i;
        }
        q.push(curr);
    }
    return min_index;
}

void insertMinToRear(queue<int>&q, int min_index)
{
    int min_val;
    int n = q.size();
    for(int i=0;i<n;i++)
    {
        int curr = q.front();
        q.pop();

        if(i!=min_index)
        {
            q.push(curr);
        }
        else
        {
            min_val=curr;
        }

    }
    q.push(min_val);
}

void sortQueue(queue<int>&q)
{
    for (int i = 1; i <= q.size(); i++) 
    { 
        int min_index = minIndex(q, q.size() - i); 
        insertMinToRear(q, min_index); 
    } 
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
    sortQueue(q);
    while (!q.empty()) 
    { 
     cout << q.front() << " "; 
     q.pop(); 
    } 
    cout << endl; 
    return 0;
}