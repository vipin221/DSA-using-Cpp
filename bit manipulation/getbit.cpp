#include<iostream>
using namespace std;

int Getbit(int n , int pos){
    return (n & (1<<pos) )!=0;
}

int main(){
    //   cout <<Getbit(5,5) <<endl;
    cout << Getbit(5, 2)<< endl; 
    cout <<Getbit(16, 1)<< endl; 
return 0;
}