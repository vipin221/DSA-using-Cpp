#include<iostream>
#include<queue>
using namespace std;

 struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second < p2.second;  // Sort based on the second value in ascending order
    }
};



int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> p;
        p.push({4,6});
        p.push({2,1});
        p.push({7,4});
        p.push({8,8});
        p.push({9,1});


        while(!p.empty()){
            cout<<p.top().first <<"-> "<< p.top().second<<endl;
            p.pop();
        }

    return 0;
}