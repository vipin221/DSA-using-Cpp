#include<iostream>
#include<vector>
using namespace std;

void PrintVec(vector<pair<int,int>> vec){
    for(int i =0; i<vec.size(); i++){
        cout<<vec[i].first << " -> " <<vec[i].second;
        cout<<endl;
    }
}

int main(){
    /*
    vector<pair<int,int>> vec = {{3,5}, {34,6}, {34,65}};
    PrintVec(vec);*/

    // nested vector or we can say 2d vetor 
    vector<int> v[3];// this does not create a 
    //vector of size 3 but it create 3 vector of size 0 .
    for(int i = 0; i<3; i++){
        int size ;
        cin>>size;
        for(int j = 0; j<size; j++){
            int x ;
            cin>>x;
            v[i].push_back(x);
        }
    }

    // for prrnting this array of vector 
    for(int i = 0; i<3; i++){
        for(int j = 0; j < v[i].size(); j++){
            cout<< v[i][j]<<" , ";
        }
        cout <<endl;
    }

return 0;
}