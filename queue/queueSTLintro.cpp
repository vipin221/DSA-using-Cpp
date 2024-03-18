#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
     cout<< "sizze of queue "<< q.size()<< endl;
    q.push(1);
    q.push(7);
    q.push(17);
    q.push(18);

    cout<< "sizze of queue "<< q.size()<< endl;

    q.pop();
    cout<< "sizze of queue "<< q.size()<< endl;

    cout <<" the front element is "<<q.front()<< endl;
    cout <<" the back element is "<<q.back();



 
return 0;
}