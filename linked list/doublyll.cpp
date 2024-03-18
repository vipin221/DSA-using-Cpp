#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    };
};

int getLength(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// insertoin at head
void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// insertion at last position
void insertAtLast(node *&head, node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }

    node *temp = new node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&tail, node *&head, int posi, int d)
{
    if (posi == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int cnt = 1;

    node *temp = head;
    while (cnt < posi - 1)
    {

        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtLast(head, tail, d);
        return;
    }
    // create node
    node *insertingNode = new node(d);
    insertingNode->next = temp->next;
    temp->next->prev = insertingNode;
    temp->next = insertingNode;
    insertingNode->prev = temp;
}
// DELETION IN DOUBLY LINKED LIST ------------------------------------------------------------

void deleteNode(node *&head, int position)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *temp = NULL;
        int cnt = 1;

        while (cnt < position)
        {

            temp = curr;
            curr = curr->next;
            cnt++;
        }
        temp->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

// print fuction
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    node *head = NULL;
    node *tail = NULL;
    //  cout<<  endl << getLength(head) << endl;
    insertAtHead(head, tail, 56);
    print(head);

    insertAtHead(head, tail, 5);
    print(head);

    insertAtLast(head, tail, 9);
    print(head);

    insertAtPosition(tail, head, 1, 78);
    print(head);

    insertAtPosition(tail, head, 4, 43);
    print(head);

    insertAtPosition(tail, head, 6, 3);
    print(head);

    // deleteNode(head, 1);
    // print(head);

    deleteNode(head, 2);
    print(head);

    return 0;
}