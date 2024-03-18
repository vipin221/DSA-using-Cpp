#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    /*
   map<string, int> m;

    // different way to insert into maps 
    //  1 
    pair<string, int> p = make_pair("vipin",1);
    m.insert(p);

    // 2
    pair<string,int> q ("maurya",2);
    m.insert(q);
    m.insert({"bhullaan", 56});


    //  3rd 
    m["kumar"] = 3;
    // 4 
    // inserted with 0 value 
    m["awtf"];


    cout <<m["awtf"]<<endl; //way to check the value for a particular key;
    cout<<m.at("vipin")<<endl; //way to check the value for a particular key;
    // cout<<m.at("vipn")<<endl;
    cout<<m["vipn"]<<endl; 

    // to checkj the size 
    cout <<m.size()<<endl;

    // to check whether an elemnet is present or not 
    cout <<m.count("hello")<<endl;
    cout <<m.count("maurya")<<endl;
    
    m.count("vipin")? cout<<"element is present": cout<<"element is not preent";
    cout<< endl;
    //if the em=lement is not present the count willl reflecct  0 else  1;
    m.erase("kumar");
    cout <<m.size()<<endl;

    // iteratotr in map  👉 to traverse alll the element in the hashmpas;
    map<string , int> :: iterator  it = m.begin();
  

    while (it != m.end()){
        cout<< it->first << " " << it->second <<endl;
        it++;
    }

    cout<<endl;
   cout <<"max number of element that the map can hold "<< m.max_size() <<endl;
   */

  vector <int> a = {1,2};
  vector <int> b = {3,4};
  vector<int> ans;


  for(auto i:a){
    ans.push_back(i);
  }

  
  for(auto i:b){
    ans.push_back(i);
  }
 
    sort(ans.begin(), ans.end());
        int size  = ans.size();
        cout <<"size  "<< size<<endl;
        float res = 0;

        if(size%2 == 1){
           res = ans[size/2];
        }
        else{
          res = (ans[(size - 1)/2] + ans[size/2])/2;
           
        }
          
       cout <<"the answer is "<<res<< endl;

return 0;
}