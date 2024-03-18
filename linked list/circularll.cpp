#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->data == NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is freed for NOde with value : " << value << endl;
    }
};
// insertion in ciruclar linked list

void insertNode(node *&tail, int value, int d)
{
    // if ll is empty
    if (tail == NULL)
    {
        node *newNode = new node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // node is not empty
    else
    {
        node *curr = tail;

        while (curr->data != value)
        {
            curr = curr->next;
        }
        // when come out of the loop means data is found
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// DELETING NODE WITH GIVE VALUE-----------------------------------------------------------
void deleteNode(node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "list is empty";
        return;
    }
    else
    {

        node *temp = tail;
        node *curr = temp->next;

        while (curr->data != element)
        {
            temp = curr;
            curr = curr->next;
        }
        temp->next = curr->next;
        if(curr == temp){
            tail = NULL;

        }
       else if (tail == curr)
        {
            tail = temp;
        }
        curr->next = NULL;
        delete curr;
    }
}

// printing code
void print(node *&tail)
{
    if(tail==NULL){
        cout<<"list is empty";
    }
    node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    node *tail = NULL;

    insertNode(tail, 5, 6);
    cout << tail->data << endl;

    insertNode(tail, 6, 2);
    print(tail);
    insertNode(tail, 2, 7);
    print(tail);
    insertNode(tail, 7, 4);
    print(tail);
    insertNode(tail, 2, 67);
    print(tail);
    insertNode(tail, 67, 3);
    print(tail);
    insertNode(tail, 6, 9);
    print(tail);

    deleteNode(tail, 7);
    print(tail);

    deleteNode(tail, 4);
    print(tail);
    deleteNode(tail, 6);
    print(tail);

    return 0;
}