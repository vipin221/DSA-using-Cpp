#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class node
{
public:
    int data;
    node* left;
    node*right;

    node( int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;  
    }
    
};


node *buildtree(node* &root){
    cout<<"Enter data for root node";
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
         return NULL;
     }
    cout<<"Enter data for left node"<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter data for right node" <<endl;
    root->right = buildtree(root->right);
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

void reverseLOT(node*root){
    stack<node*> st;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        node*temp = q.front();
        st.push(temp);
        q.pop();
        if( temp == NULL){
            q.push(NULL);
        }
       else{
            if(temp->right){
                 q.push(temp->right);
            }
            if(temp->left) {
                q.push(temp->left);
            }       
        }
     
    }

    while(!st.empty()){
        if(st.top() == NULL)
         cout<<endl;
        cout<<st.top()->data<<" ";
        st.pop();
    }

}
void Inorder(node * root){
    if(root == NULL) return ;

    Inorder(root->left);
    cout<< root->data <<" ";
    Inorder(root->right);
}
void PreOrder(node * root){
    if(root == NULL) return ;

    cout<< root->data <<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(node * root){
    if(root == NULL) return ;

   PostOrder(root->left);
   PostOrder(root->right);
    cout<< root->data <<" ";
}

void buildFromLevelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter data for root node";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for left node"<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data for right node"<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }

}

int main(){
    node* root = NULL;

   root =  buildtree(root);
//    buildFromLevelOrderTraversal(root);
//    levelOrderTraversal(root);

   // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
 
// reverseLOT(root);
   Inorder(root);
/*
   cout<<endl;
   PreOrder(root);
   cout<<endl;

   PostOrder(root);
   */ 


 
return 0;
}