// application
// when we push element into stack and then poping it the element get reverse

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "my name is vipin";

    stack<char> s;

    for(int i = 0; i<str.length(); i++){
        char ch = str[i];
        s.push(ch);
    }

    string ans ="";

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();

    }
    cout << "the answer is -->"<<endl;
    cout<< ans<< endl;

 
return 0;
}