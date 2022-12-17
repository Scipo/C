// C++ program to interleave the first half of the queue 
// with the second half 
#include<iostream>
#include<queue>
#include<stack>

using namespace std; 

// Function to interleave the queue 
void interLeaveQueue(queue<int>& q) 
{ 
	// To check the even number of elements 
	if (q.size() % 2 != 0) 
		cout << "Input even number of integers." << endl; 

	// Initialize an empty stack of int type 
	stack<int> s; 
	int halfSize = q.size() / 2; 

	// Push first half elements into the stack 
	// queue:16 17 18 19 20, stack: 15(T) 14 13 12 11 
	for (int i = 0; i < halfSize; i++) { 
		s.push(q.front()); 
		q.pop(); 
	} 

	// enqueue back the stack elements 
	// queue: 16 17 18 19 20 15 14 13 12 11 
	while (!s.empty()) { 
		q.push(s.top()); 
		s.pop(); 
	} 

	// dequeue the first half elements of queue 
	// and enqueue them back 
	// queue: 15 14 13 12 11 16 17 18 19 20 
	for (int i = 0; i < halfSize; i++) { 
		q.push(q.front()); 
		q.pop(); 
	} 

	// Again push the first half elements into the stack 
	// queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15 
	for (int i = 0; i < halfSize; i++) { 
		s.push(q.front()); 
		q.pop(); 
	} 

	// interleave the elements of queue and stack 
	// queue: 11 16 12 17 13 18 14 19 15 20 
	while (!s.empty()) { 
		q.push(s.top()); 
		s.pop(); 
		q.push(q.front()); 
		q.pop(); 
	} 
} 
void printQueue(queue<int>&queue)
{
    int n = queue.size();
    for(int i=0;i<n;i++)
    {
        cout<<queue.front()<<" ";
        queue.pop();
    }
    cout<<endl;
}
int main() 
{ 
	queue<int> q; 
	int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    } 
	interLeaveQueue(q); 
    printQueue(q);
	return 0; 
} 
