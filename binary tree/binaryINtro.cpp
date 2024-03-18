#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
 
 };
   
 node *buildTree(node * root){
    cout<< "Enter the data "<< endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }
    cout<< "Enter the data for inserting in left of "<<data<< endl;
    root->left = buildTree(root->left);
    cout<< "Enter the data for inserting in right of "<<data<< endl;
    root->right = buildTree(root->right);
    return root;


 }
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
    void inOrder( node * root ){
        if(root ==NULL )
        return;

       inOrder(root->left);
       cout<< root->data<< " ";
       inOrder(root->right);
    }
    void preOrder( node * root ){
        if(root ==NULL )
        return;

        cout<< root->data<< " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder( node * root ){
        if(root ==NULL )
        return;

        postOrder(root->left);
        postOrder(root->right);
        cout<< root->data<< " ";
    }
  
// creating tree from level order traversall;
void treeFromlevelOrder(node * &root){
    cout<<"ENter the data"<< endl;
    int data; 
    cin >>data;
    root = new node(data);
    queue <node*> q;
    q.push(root);


    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<" Enter left node for  "<< temp->data<< endl;
        int leftdata;
        cin >> leftdata;
        if(leftdata!= -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<" Enter right node for  "<< temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata!= -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }

    }

}


int main(){
    node * root = NULL;

    treeFromlevelOrder(root);
    levelOrderTraversal(root);
    /*

    //creating a root node;
    root = buildTree(root);
    cout << "printing the level order traversal:"<< endl;
    levelOrderTraversal(root);

    cout<< " inorder traversal is : "<< endl;
    inOrder(root);
    cout << endl;
    cout<< " preOrder traversal is : "<< endl; 
    preOrder(root);
     cout << endl;
    cout<< " postorder traversal is : "<< endl;
     postOrder(root);
      cout << endl;
    */
 
return 0;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<double> averageOfLevels(TreeNode* root) {
//         vector<double> result;
//         if(root==NULL){
//             return result;
//         }

//         queue <TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
            
//             int size = q.size();
//             double sum = 0;
//             for(int i = 0; i<size; i++){

//                 TreeNode* temp = q.front();
//                 q.pop();
                
//                 sum += temp->val;

//                 if(root->left){
//                     q.push(root->left);
//                 }

//                 if(root->right){
//                     q.push(root->right);
//                 }
               
//             }
//              double avg = sum/size;
//              result.push_back(avg);
//         }
//         return result;

        
//     }
// };
