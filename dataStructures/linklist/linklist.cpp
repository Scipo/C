#include<iostream>
using namespace std;

struct node
{
    int data;
    node* linkNext;
};

//node* head;//global variable 

//insert the node
void insert(node** head,int x)
{
   node* tmp = new node();
   tmp->data = x; 
   tmp->linkNext = NULL;
   if(*head!=NULL) tmp->linkNext = *head;
   *head = tmp;
}

//Insert the node of n-th possiotion
void insert_nth(node** head, int data, int n)
{
    node* tmp = new node();
    tmp->data = data;
    tmp->linkNext = NULL;
    if(n==1)
    {
        tmp->linkNext = *head;
        *head = tmp;
        return;
    }
    node* tmp1 = *head;
    for(int i=0;i<n-2;i++)
    {
        tmp1=tmp1->linkNext;
    }
    tmp->linkNext=tmp1->linkNext;
    tmp1->linkNext=tmp;
}

//delete the node ot n-th position
void delete_node(node** head, int n)
{
    node* tmp = *head;
    if(n==1)
    {
        *head=tmp->linkNext;//head points to second node
        delete tmp;
        return;
    }
    for(int i=0;i<n-2;i++)
    {
        tmp=tmp->linkNext;
    }
    node* tmp1 = tmp->linkNext;
    tmp->linkNext=tmp1->linkNext;
    delete tmp1;
}
// Reverse a linklist iteractive
void reverce(node** head)
{
    node *curret,*prev,*next;
    curret = *head;
    prev = NULL;

    while(curret!=NULL)
    {
        next = curret->linkNext;
        curret->linkNext=prev;
        
        prev = curret;
        curret = next;
    }
    *head = prev;
}
//print the nodes
void print_nodes(node* head)
{
    cout<<"LinkList Print: ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->linkNext;
    }
    cout<<endl;
}
//print nodes recrusive/reverse
void print_rec(node* head)
{
    if(head==NULL){
        cout<<endl;
        return;
    }
    print_rec(head->linkNext);
    cout<<head->data<<" ";
}
//recursive reverse of linklist
node* head;
void recursive_reverse(node* p)
{
    if(p->linkNext==NULL)
    {
        head=p;
        return;
    }
    recursive_reverse(p->linkNext);
    node* q = p->linkNext;
    q->linkNext=p;
    p->linkNext=NULL;
}

int main()
{
    node* head = NULL; //points to nowhere
    
    /*int n;
    cout<<"Enter a number for the size of the nodes: ";
    cin>>n;
    for(int i =0;i<n;i++)
    {
        cout<<"Enter numbers: "<<endl;
        int x;
        cin>>x;
        insert(&head,x);
        print_nodes(head);
    }*/

    //instert the nodes of n-th possiotion
    
    insert_nth(&head,2,1);
    insert_nth(&head,3,2);
    insert_nth(&head,4,1);
    insert_nth(&head,5,2);
    
    print_nodes(head);
    //recursive reverse nods;
    //cout<<"recursive reverse nods"<<endl;
    //recursive_reverse(head);
    //print_nodes(head);


    //delete node of n-th position
    int n;
    
    insert(&head,2);
    insert(&head,4);
    insert(&head,6);
    insert(&head,8);
    print_nodes(head);
    cout<<endl;
    
    //reverse
    cout<<"Reversed "<<endl;
    reverce(&head);
    print_nodes(head);

    cout<<"Enter position n: ";
    cin>>n;
    delete_node(&head,n);
    cout<<endl;
    
    cout<<"New nodes";
    cout<<endl;
    print_nodes(head);
   
    return 0;
}