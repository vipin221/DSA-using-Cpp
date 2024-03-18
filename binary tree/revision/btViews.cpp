#include<iostream>
#include<queue>
#include<map>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

        node (int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

// creation of tree 
node * buildTree(node * &root){
    cout<<"inter data for root"<<endl;
    int data;
    cin>>data;
    if(data == -1) return NULL;

    root = new node(data);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

// traversals 
// inOrder traversal 
void INorder(node* root){
    if(root == NULL) return;

    INorder(root->left);
    cout<<root->data<< " ";
    INorder(root->left);
}
void preOrder(node* root){
    if(root == NULL) return;

    cout<<root->data<< " ";
    preOrder(root->left);
    preOrder(root->left);
}
void postOrder(node*root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->left);
    cout<<root->data<< " ";
}

// levelOrderTraversal 

void levelOrderTraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp ==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

      
    }
}

//code for leftView of BT
void leftViewOfBT(node* root,int level, vector<int>&leftView){
    if(root == NULL) return;
    if(level == leftView.size()){
        leftView.push_back(root->data);
    }

    leftViewOfBT(root->left,level+1, leftView);
    leftViewOfBT(root->right,level+1, leftView);
}
//code for rightView of BT
void righttViewOfBT(node* root,int level, vector<int>&rightView){
    if(root == NULL) return;
    if(level == rightView.size()){
        rightView.push_back(root->data);
    }
        // reversed call give right view of bt
    leftViewOfBT(root->right,level+1,rightView);
    leftViewOfBT(root->left,level+1, rightView);
}

void topViewOfBT(node*root){

    queue <pair<node*,int>> q;
    q.push({root,0});
    map<int,int>HorizontalDistanceToRoot;


    while(!q.empty()){
        pair<node*,int>temp = q.front();
        node*frontNode = temp.first;
        int hd = temp.second;

        if(HorizontalDistanceToRoot.find(hd) == HorizontalDistanceToRoot.end()){
            HorizontalDistanceToRoot[hd] = root->data;
        }

        if(root->left){
            q.push({root->left,hd-1});
        }
        if(root->right){
            q.push({root->right,hd+1});
        }
    }

    for(auto i:HorizontalDistanceToRoot){
        cout<<i.second<<" ";
    }
    cout<<endl;
}
void BottomViewOfBT(node*root){

    queue <pair<node*,int>> q;
    q.push({root,0});
    map<int,int>HorizontalDistanceToRoot;


    while(!q.empty()){
        pair<node*,int>temp = q.front();
        node*frontNode = temp.first;
        int hd = temp.second;

       //just Removing if condition
        HorizontalDistanceToRoot[hd] = root->data;
        

        if(root->left){
            q.push({root->left,hd-1});
        }
        if(root->right){
            q.push({root->right,hd+1});
        }
    }

    for(auto i:HorizontalDistanceToRoot){
        cout<<i.second<<" ";
    }
    cout<<endl;
}


int main(){
    node* root = NULL;
    root = buildTree(root);
    //10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    cout<<"INorder traversal -> ";
    INorder(root);
    cout<<endl;

    cout<<"PreOrder traversal -> ";
    preOrder(root);
    cout<<endl;

    cout<<"PostOrder traversal -> ";
    postOrder(root);
    cout<<endl;


    //leftveiw
    vector<int>leftView;
    leftViewOfBT(root,0,leftView);
    for(int i =0; i<leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }
    cout<<endl;




return 0;
}