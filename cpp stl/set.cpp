#include<iostream>
#include<set>
using namespace std;

int main(){
    int arr[] = {43,4,3,5,3,4,2,3,1,3,1,3,1,4,4,54,3,2};
     set<pair<int,int> > s;
    for(int i = 0; i<18; i++){
        int j = 0;
        s.insert({arr[i],++j})

    }
   




 
return 0;
}