#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* InsertIntoBSt(Node*root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = InsertIntoBSt(root->left, data);
    }
    if(data > root->data){
        root->right = InsertIntoBSt(root->right, data);
    }
    return root;
}

Node * findMaxi(Node*root){
    if(root == NULL) return NULL;
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

//delete From BST
Node* deleteFormBST(Node*root, int target){
    if(root == NULL) return NULL;

    if(root->data ==  target){
        // 4 cases for deletion in binary tree 
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            // ager left NULL nhi hai aur right  NULL hai 
            Node* leftSubTree = root->left;
            delete root;
            return leftSubTree;
        }
        else if(root->left == NULL && root->right != NULL){
            // ager right NULL nhi hai aur left  NULL hai 
            Node* rightSubTree = root->right;
            delete root;
            return rightSubTree;
        }
        else{
            // ager left aur right dono hi not null ho to 

            // find kro maximum value from left sub tree 
            Node*maxNodeValueFromLeftSubTree = findMaxi(root->left);

            // replace kro root ke data ko maximum vlaue ke sath
            root->data = maxNodeValueFromLeftSubTree->data;
            // delete maximum value from left subtree
            root->left = deleteFormBST(root->left, maxNodeValueFromLeftSubTree->data);
        }
        


    }
    else if(root->data > target){
        root->left = deleteFormBST(root->left, target);
    }
    else{
        root->right = deleteFormBST(root->right, target);
    }
    return root;
}

// creating bst from inoder 

Node* BSTfromInorder(int arr[], int start, int end){
    if(start > end) return NULL;

    int mid = (start+end)/2;

    int element = arr[mid];
    Node*root = new Node(element);

    root->left = BSTfromInorder(arr, start, mid-1);
    root->right = BSTfromInorder(arr, mid+1, end);

    return root;

}


void creatBST(Node * &root){
    cout<<"Enter data ";
    int data;
    cin>>data;
    while(data != -1){
        root = InsertIntoBSt(root,data);
        cout<<"Enter Data "<< endl;
        cin>>data;

    }
}

void LOL(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }


}

int main(){

    // Node* root = NULL;
    // creatBST(root);
    // LOL(root);

    // cout << "Enter Node to delete"<<endl;
    // int target;
    // cin>> target;
    // while(target != -1){
    //      root = deleteFormBST(root,target);
    //      cout<<"deleted Successfully"<<endl<<endl;
    //      LOL(root);
    //      cout << "Enter Next  Node to be delete"<<endl;
    //     cin>> target;
    // }
    int arr[] = {20,30,37,40,50,60,70,80,90};
    Node* root = BSTfromInorder(arr, 0, 8);
    LOL(root);



 
return 0;
}