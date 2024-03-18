#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>adj;
    void AddEdge(int u, int v , int weight){
        pair<int,int>p(v,weight);
        adj[u].push_back(p);
    }
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<< "->";
            for(auto j:i.second){
                cout<<"["<<j.first <<","<<j.second<<"] ";
            }
            cout<<endl;
        }
    }
    void dfs(int node,unordered_map<int,bool>&visited , stack<int>&st){
        visited[node] = true;

        for(auto i:adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,st);
            }
        } 
        st.push(node);

    }

   void findPAth(int src, stack<int>&st,vector<int> &dist){
        dist[src] = 0;

        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(dist[top] != INT_MAX){
                for(auto i:adj[top]){
                    dist[i.first] = min((i.second + dist[top]),dist[i.first]);
                }
            }
        }

    }

};

int main(){
    Graph g;
    g.AddEdge(0,1,5);
    g.AddEdge(0,2,3);
    g.AddEdge(1,3,6);
    g.AddEdge(1,2,2);
    g.AddEdge(2,3,7);
    g.AddEdge(2,4,4);
    g.AddEdge(2,5,2);
    g.AddEdge(3,4,-1);
    g.AddEdge(4,5,-2);

    // g.printAdj();

    unordered_map<int,bool>visited;
    stack<int>s;

    int n = 6;
    for(int i=0; i<n; i++){
        if(!visited[i]){
           g.dfs(i,visited,s);
        }
    }

    // cout <<"topoSort is  "<<endl;
    // while(!s.empty()){
    //     cout<<s.top()<< " ";
    //     s.pop();
    // }
    cout << endl;
    cout << endl;
    cout << endl;

    int src =1;
    vector<int>dist(n);

    for(int i =0; i<n; i++ ){
        dist[i] = INT_MAX;
    }


    g.findPAth(src,s,dist);

    cout<<"the answer is "<<endl<<endl;
    for(int i =0; i<6; i++){
        cout<<dist[i] << " ";
    }
    cout <<endl;



 
return 0;
}