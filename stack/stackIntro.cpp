#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <int> s;

    s.push(4);
    s.push(3);
    s.push(7);
    s.push(0);
    s.push(9);
    cout<<s.top() << endl;
    s.pop();
     cout<<s.top()<< endl;
     
    if(s.empty()){
        cout<<"stack is empty "<<endl;

    }
    else{
        cout<<"stack is not empty"<< endl;
    }


cout<<s.size();

    return 0;
}

