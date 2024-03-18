#include<iostream>
// #include<pair>
#include<utility>
#include<vector>

using namespace std;

int main(){
    vector<int> v = {4,6,3,7,3,46,7,4,2};
    vector<int> ::iterator it =  v.begin(); // syntax to declare iterator
    // we can also use auto 
   
    for(it = v.begin(); it != v.end(); it++){
        cout<<(*it) << " ";
    }
    cout <<endl<<endl;

    // for pair 
    vector<pair<int,string>> p = {{3, "vipin"},{4,"kumar"},{2, "maurya"} };



    /* //
     vector<pair<int,string>> ::iterator i; //declaration
    for(i = p.begin(); i != p.end(); i++){
        cout<< (*i).first << " "<<(*i).second<<endl;
    }
    */
   
    // note ------>> (*i).first <=same=> i->first ;
    // note ------>> (*i).second <=same=> i->second ;

   //the above iteration are lengthy  we can simplify as 
    for(auto i : p){
        cout<< i.first << " "<<i.second<<endl;
    }

    cout<<endl;
    return 0;
}   