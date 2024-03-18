#include <bits/stdc++.h>
using namespace std;
/*
template <class ForwardIterator, class T>
ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val);
*/


int main()
{
    // vector<int> vec = {1,2, 4, 4, 5, 5 ,6, 7, 8 };
    // sort(vec.begin(), vec.end());
    // for(auto i:vec){
    //     cout<<i<<" ";

    // }cout<<endl;

    // auto i = (lower_bound(vec.begin(), vec.end(),5-vec.begin()));
    // cout<<*i;
    int n,m;
    cin>>n>>m;

    vector<vector<int>>ar(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j =0; j<m;j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }

   
    return 0;
}