
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor........
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// insertion at last
void insertAtTail(node *&tail, int d)
{
    // create a new node that you want to be insert
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//  insertion at starting point
void insertAtHead(node *&head, int d)
{
    //  create a new node
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

// insrting at any position
void insertInBetween(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    //  creating a new node that is to be added
    node *inBetween = new node(d);
    inBetween->next = temp->next;
    temp->next = inBetween;
}
// ----------------------------------------------------------------------------------------
// deletion of node //////

void deleteNode(int position, node *&head)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        // free memory
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
//-------------------------------------------------------------------------------------------

// traversing
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << endl;
}

// cycle detection in -----------------------------------------------------------

node *floydDetectloop(node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (fast == slow)
        {

            return slow;
        }
    }
    return NULL;
}

// finding the starting node of loop------------------------------------------------------------

node *startingNode(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *intersection = floydDetectloop(head);
    node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

int main()
{
    node *node1 = new node(12);
    // cout << node1->data << endl;
    node *head = node1;
    node *tail = node1;
    // cout << (*node1).data <<  endl;

    insertAtHead(head, 65);
    print(head);
    insertAtHead(head, 6);
    print(head);
    insertAtHead(head, 45);
    print(head);
    insertAtTail(tail, 90);
    print(head);
    insertAtTail(tail, 50);
    print(head);
    insertAtTail(tail, 0);
    print(head);
    insertInBetween(tail, head, 4, 66);
    print(head);
    insertInBetween(tail, head, 9, 644);
    print(head);
    tail->next = head->next;

    // deleteNode(1, head);
    //  print(head);
    // deleteNode(3, head);
    // print(head);
    // deleteNode(7, head);
    // print(head);
    if (floydDetectloop(head) != NULL)
        cout << "cycle is present";
    else
    {
        cout << " cycle is not present";
    }
    node *loop = startingNode(head);
    cout << "starting node is present at " << loop->data;

    return 0;
}