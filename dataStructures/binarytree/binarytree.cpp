#include<iostream>
#include<queue>

using namespace std;

//Definition of nodes in Binary tree
struct binarytree
{
    int data;
    binarytree* left;
    binarytree* right;
};

//Create a new node in the heap memmory
binarytree* GetNewNode(int data)
{
    binarytree* newNode = new binarytree();
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
} 
//Insert data and return address of root node
binarytree* insertNode(binarytree* root, int data)
{
    if(root==NULL)//if root is null create new node
    {
        root=GetNewNode(data);
    }
    else if(root->data>=data)
    {
        root->left=insertNode(root->left,data);
    }
    else
    {
        root->right=insertNode(root->right,data);    
    }
    return root;
}
    //Searching for element in BST
    bool search(binarytree* root, int data)
    {
      if(root==NULL)
      {
          return false;
      }   
      else if(root->data==data)
      {
          return true;
      }
      else if(root->data>=data)
      {
          return search(root->left, data);
      }
      else
      {
          return search(root->right,data);
      }
     
    }
 //Find max and min elements   
 int findMin(binarytree* root)
 {
     if(root==NULL)
     {
         cout<<"Empty"<<endl;
         return -1;
     }
     while(root->left!=NULL){
        root = root->left;
     }
     return root->data;
}

int finMax(binarytree* root)
{
    if(root==NULL)
     {
         cout<<"Empty"<<endl;
         return -1;
     }
    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;
}

//Find hight of a binary search tree
int findHeight(binarytree* root)
{
    if(root == NULL)
        return -1;

   return max(findHeight(root->left),findHeight(root->right))+1;     
}
//Level Order in BST - BFS
void levelOrder(binarytree* root)
{
    if(root == NULL)
    {
        return;
    }
    queue<binarytree*>q;
    q.push(root);

    while(!q.empty()){
        binarytree* current = q.front();
        cout<<current->data<<" ";
        
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        
        q.pop();
        
    }
    cout<<endl;
}
// Preoder permutation
void preoder(binarytree* root)
{
    if(root == NULL) return;

    cout<<root->data<<" "<<endl;
   
    preoder(root->left);
    preoder(root->right);
}
//Inoder permutation
void inoder(binarytree* root)
{
    if(root == NULL)return;

    inoder(root->left);
    cout<<root->data<<" "<<endl;
    inoder(root->right);
}

//Postorder permutation
void postorder(binarytree* root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "<<endl;
}

//check if a tree is a binary search tree
bool isBST(binarytree* root, int min, int max)
{
    if(root == NULL) return -1;

    if((root->data >= min && root->data <= max) 
    && isBST(root->left,min,root->data) 
    && isBST(root->right,root->data,max))
    {
        return true;
    }
    else
    {
        return false;
    }
      
}
bool isBinarySearchTree(binarytree* root)
{
    
    return isBST(root,INT32_MIN,INT32_MAX);
}

//Find min new function
binarytree* findMinNew(binarytree* root)
{
    while(root->left!=NULL){
        root= root->left;
    }
    return root;
}

//Delete elements from a binary search tree
binarytree* delete_Node(binarytree* root, int data)
{
    if(root==NULL)return root;
    else if(data<root->data)root->left=delete_Node(root->left,data);
    else if (data>root->data)root->right=delete_Node(root->right,data);
    else
    {
        //Case 1: No child(node is a leaf)
        if (root->left==NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //Case 2: has one child
        else if (root->left==NULL)
        {
            binarytree* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if (root->right==NULL)
        {
            binarytree* tmp = root;
            root = root->left;
            delete tmp;
        }
        //Case 3: has two children
        else
        {
            binarytree* tmp = findMinNew(root->right);
            root->data = tmp->data;
            root->right=delete_Node(root->right,tmp->data);
        }
    }
    return root;
}

int main()
{
    binarytree* root = NULL;
    root = insertNode(root,15);
    root = insertNode(root,20);
    root = insertNode(root,25);
    root = insertNode(root,30);
    root = insertNode(root,8);
    root = insertNode(root,5);
    root = insertNode(root,10);
    root = insertNode(root,12);
    root = insertNode(root,17);
    int num;
    
    //find min max element
    cout<<"Min: "<<findMin(root)<<endl;
    cout<<"Max: "<<finMax(root)<<endl;
    
    cout<<endl;

    //find height
    cout<<"Height of BST: "<<findHeight(root)<<endl;
    
    cout<<endl;

    //Level order traversal(BFS)
    levelOrder(root);
    
    cout<<endl;

    //Preoder
    cout<<"Preorder: "<<endl;
    preoder(root);
    
    cout<<endl;

    //is a tree is Binary seach tree
    cout<<"Binary Search Tree: ";
    cout<<(isBinarySearchTree(root)?"YES":"NO")<<endl;
    
    cout<<endl;

    //Delete Node
    root=delete_Node(root,5);
    
    //Inorder
    cout<<"Inorder: "<<endl;
    inoder(root);
    cout<<endl;

    //seach for element if it there 
    cout<<"Number for search: ";
    cin>>num;
    if(search(root,num)==true)
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;
 return 0;
}