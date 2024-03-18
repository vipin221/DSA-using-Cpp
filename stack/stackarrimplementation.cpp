#include <iostream>

using namespace std;

class stack
{
public:
    int *arr;
    int size;
    int top;

    stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    // push elemnet in stack
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack is overflow" << endl;
        }
    }
    // pop element from stack
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << " stack is empty" << endl;
        }
    }

    int peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty"<< endl;
            return -1;
        }
    }

    bool IsEmpty()
    {
        if (top = -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack st(5);
    st.push(3);
    st.push(66);
    cout<< st.peek()<<endl;
   st.pop();
    cout<< st.peek()<<endl;
   st.pop();
   cout << st.peek()<<endl;

   cout << st.IsEmpty()<< endl;

    return 0;
}