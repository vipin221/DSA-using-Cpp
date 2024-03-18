#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int remove(int* arr, int n){
    vector<int> ans;
    for(int i = 0; i<n; i++){
        ans.push_back(arr[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i<n; i++){
        cout<< ans[i];
    }
    return -1;
}

int main(){
    int arr[]= {9,1,2,3,1,5};

    int N = sizeof(arr)/sizeof(int);
    remove(arr,N);

 
return 0;
}