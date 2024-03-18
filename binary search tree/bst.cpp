#include<iostream>
#include<queue>
using namespace std;

class node {
    public :
    int data ; 
    node *left;
    node * right;

    //constructor
    node(int data){
        this->data = data ;
        this->left = NULL;
        this->right = NULL;
    }
};

// function for level order traversal 
 void levelOrderTraversal(node *root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            node* temp = q.front();
            q.pop();

            if(temp == NULL){
                cout<< endl;
                if(!q.empty()){
                        q.push(NULL);
                    }   
                }
            else{
                 cout << temp->data << " ";
                 if(temp-> left){
                    q.push(temp->left);
                }
                if(temp-> right){
                    q.push(temp->right);
                }
            }
        }


    }
// inserting data  into  into binary tree 

node* insertIntoBST(node*root, int d){
    // base case 
    if(root == NULL){
        root = new node(d);
        return root;
    }
    if(d > root->data){
       // inserting into right 
        root->right = insertIntoBST(root->right, d);
    }

    else{
           // inserting into left 
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

// Inoreder traversal fucntion 
void Inorder(node*root){
    if(root == NULL){
         return;
    }

    Inorder(root->left);
    cout<< root->data<< " ";
    Inorder(root->right);
}

// preorder traversal function 
void preorder(node*root){
    if(root == NULL){
         return;
    }

    cout<< root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}

// post oreder traversal function 
void postorder(node*root){
    if(root == NULL){
         return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<< root->data<< " ";
}


// taking input to add data in bst
void inputdata(node* &root){
    int data ;
    cin>>data;

    while(data != -1)
    {
       root =  insertIntoBST(root, data);
       cin >> data;
    }
}
//min value of bst 
node* minValue(node * root){

    node* temp = root;
    while(temp->left != NULL){
       temp = (temp->left);

    }
    return temp;
}

// max Value in bst 
node* maxValue(node * root){
    
    node* temp = root;
    while(temp->right != NULL){
       temp = (temp->right);

    }
    return temp;
}

// 👉IMPortant 👉deleteion in bst 
node* deleteFromBST(node * &root ,int val){
    if(root == NULL) return root;

    if(root->data == val){
        // cases :
        // 1st case: zero child 
        if (root ->left == NULL && root ->right  == NULL){
            delete root;
            return NULL;
        }
        //singal child (left)
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;

        }
        //singal child (right)
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;

        }
        // having 2 child 
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right , mini);
            return root;
        }
    }
    else if(root->data > val){
       root->left =  deleteFromBST(root->left, val);
       return root;
    }
    else{
        root->right =  deleteFromBST(root->right, val);
        return root;
    }
}

int main(){

    node* root = NULL;
    cout<<"enter data create bst: "<<endl;
    inputdata(root);

    cout<<"Printing the data" << endl;
    levelOrderTraversal(root);

    cout<<endl<< "printing in inorder traversal e.i., LNR"<<endl;
    Inorder(root);
    cout<<endl<< "printing in preorder traversal e.i., NLR"<<endl;
    preorder(root);
    cout<< endl<<"printing in postorder traversal e.i., LRN"<<endl;
    postorder(root);

    cout <<endl <<"the minimun value in bst is: " <<minValue(root) -> data<<endl;
    cout <<endl <<"the maximum value in bst is: " <<maxValue(root) ->data <<endl;

    root =  deleteFromBST(root, 50);


    cout<<"Printing the data" << endl;
    levelOrderTraversal(root);
    cout<<endl<< "printing in inorder traversal e.i., LNR"<<endl;
    Inorder(root);
    cout<<endl<< "printing in preorder traversal e.i., NLR"<<endl;
    preorder(root);
    cout<< endl<<"printing in postorder traversal e.i., LRN"<<endl;
    postorder(root);

    cout <<endl <<"the minimun value in bst is: " <<minValue(root) -> data <<endl;
    cout <<endl <<"the maximum value in bst is: " <<maxValue(root) ->data <<endl;

   

return 0;
}
//50 20 70 10 30 90 110 -1