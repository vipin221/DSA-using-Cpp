#include<iostream>
#include<vector>
using namespace std;

int main(){
int arr[]= {5,4,-1,7,8};
int size = sizeof(arr)/sizeof(int);
int maxi = 0;
// for maximum subarray 
for( int i = 0; i<size; i++){
   
    int sum =0;
    for(int j = i; j< size; j++){
        sum = sum + arr[j];
        maxi = max(maxi ,sum);
    }
}
cout << maxi;

 
return 0;
}