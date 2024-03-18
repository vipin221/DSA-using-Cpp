#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node* &root)
{

    cout << "Enter the Data "<< endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void Inorder(node * root){
    if(root == NULL) return ;

    Inorder(root->left);
    cout<< root->data<<" ";
    Inorder(root->right);
}

void createMapOfInorder(int inOrder[], unordered_map<int,int>&mp, int size){

    for(int i =0;i<size; i++){
        mp[inOrder[i]] = i; 
    }

}


// creating node from INorder and PreOrder 

 node *cretingTreeFromPreAndIn( int inOrder[], int preOrder[], int& preOrderIndex, int inOrderStart, int inOrderEnd, int size,unordered_map<int,int>&mp){
    if(preOrderIndex >= size  || inOrderStart > inOrderEnd) return NULL;

    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    int index = mp[element];

    node *root = new node(element);
    root->left = cretingTreeFromPreAndIn(inOrder, preOrder,preOrderIndex,inOrderStart,index-1,  size, mp);
    root->right = cretingTreeFromPreAndIn(inOrder, preOrder,preOrderIndex,index+1,inOrderEnd, size, mp);

    return root;
 }

//  creating from postOrder 
 node *creteTreeFromPostAndIn( int inOrder[], int postOrder[], int& postOrderIndex, int inOrderStart, int inOrderEnd, int size,unordered_map<int,int>&mp){
    if(postOrderIndex < 0  || inOrderStart > inOrderEnd) return NULL;

    int element = postOrder[postOrderIndex];
    postOrderIndex--; //going to index zero from last 

    int index = mp[element]; // finding index in in order 

    node *root = new node(element); // creating root 
    // we have to build tree from right side only 
    root->right = creteTreeFromPostAndIn(inOrder, postOrder,postOrderIndex,index+1,inOrderEnd, size, mp);
    root->left = creteTreeFromPostAndIn(inOrder, postOrder,postOrderIndex,inOrderStart,index-1,  size, mp);

    return root;
 }


 void levelOrderTraversal(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";  
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

        }


    }
}



int main()
{
 //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    // root = buildTree(root);
    // Inorder(root);
/*
            (2)
           /    \
         (8)     (4)
         / \       \
     (10)  (6)   ( 12)
*/
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int postOrder[] = {10,6,8,12,4,2};
    int preOrderIndex = 0;
    int postOrderIndex = 5;
    unordered_map<int,int>maping;
    createMapOfInorder(inOrder,maping ,6);
    // root = cretingTreeFromPreAndIn(inOrder, preOrder,preOrderIndex,0, 5, 6,maping);
    root = creteTreeFromPostAndIn(inOrder, postOrder,postOrderIndex,0, 5, 6,maping);
    levelOrderTraversal(root);

    return 0;
}