#include<iostream>
#include<stack>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>adjList;

    void addEdge(int u ,int v , int wt, bool dir){
         adjList[u].push_back({v,wt});
         if(dir == 0){
             adjList[v].push_back({u, wt});
         }

    }

    void printGraph(){
        for(auto it: adjList){
            cout << it.first<< "->"<<"{";
            for(auto j: it.second){
                cout<<"{"<<j.first <<","<< j.second<<"},";
            }
            cout<<"}"<<endl;
        }
    }

    // to find topological order 
    void findTopo(stack<int>&s, vector<bool>&vis, int src){
        vis[src] = true;
        
        for(auto nbrpair:adjList[src]){
            if(!vis[nbrpair.first])
                findTopo(s, vis, nbrpair.first);
        }

        s.push(src);
    }

    // this is actual code for finding the shortest path from src to each node  

     void findShortestPath(stack<int>s, int n){
        vector<int>dist(n,INT_MAX);

        int src = s.top();
        s.pop();
        dist[src] = 0;

        for(auto nbrpair:adjList[src]){
            int nbrNode = nbrpair.first;
            int nbrweight = nbrpair.second;
            if(dist[src] + nbrweight < dist[nbrNode]){
                dist[nbrNode] = dist[src] + nbrweight;
            }
        }

        while(!s.empty()){
            int src = s.top();
            s.pop();

            for (auto nbrpair : adjList[src])
            {
                int nbrNode = nbrpair.first;
                int nbrweight = nbrpair.second;
                if (dist[src] + nbrweight < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrweight;
                }
            }
        }

        for(auto d :dist){
            cout<<d<<", ";

        }
        cout<<endl;

     }
};

int main(){

    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    // g.printGraph();
    stack<int>s;
    vector<bool>vis(5);

    g.findTopo(s, vis, 0);
    // cout<<s.size()<<endl;

    // while(!s.empty()){
    //     cout<<s.top()<<"->";
    //     s.pop();
    // }

    g.findShortestPath(s,5);


    
}