#include<iostream>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

template<typename T> //
class Graph{
    public:
    unordered_map<T, list<pair<T,int>>>adjList;
    
    void addEdge(T u, T v, int wt, bool dir){
        adjList[u].push_back({v,wt});
        if(dir == 0){
            adjList[v].push_back({u,wt});
        }
    }

     void printGraph(){
        for(auto i:adjList){
            cout<<i.first<<"->"<<"{ ";
            for(auto j: i.second){
                cout<<"{ "<<j.first<<", "<<j.second<< " } ";
            }
            cout<<" }"<<endl;
        }
    }


     void bfsTraversal(T src, unordered_map<char, bool> &vis){
        queue<T> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            T frontNode = q.front();
            cout<<frontNode<<"->";
            q.pop();

            for(auto nbr : adjList[frontNode]){
                if(!vis[nbr.first]){
                    q.push(nbr.first);
                    vis[nbr.first] = true;
                }
            }
        }

    }
    void dfs(T src, unordered_map<T,bool>&vis){
        vis[src] = true;
        cout<<src<< "->";

        for(auto nbr: adjList[src]){
            if(!vis[nbr.first]) dfs(nbr.first, vis);
        }
    }

};

int main(){



    Graph<char> gg; 
    gg.addEdge('a','b',23,0);
    gg.addEdge('a','c',34,0);
    gg.addEdge('b','c',22,0);
    gg.addEdge('b','d',23,0);
    gg.addEdge('b','e',44,0);                                           
    gg.addEdge('e','f',44,0);
    
    unordered_map<char,bool>visited;
    // directly pass source node if the graph is connected
    // gg.bfsTraversal('a', visited);

     // if  the graph is disconnected the do this
    //  for(auto ch = 'a'; ch<='f'; ch++){
    //     if(!visited[ch]) gg.bfsTraversal(ch, visited);
    //  }

    // similarly for dfs traversal 
    for(auto ch  = 'a'; ch <= 'f'; ch++){
        if(!visited[ch]) gg.dfs(ch, visited);
    }

    


    

  
    

    // gg.printGraph();

 
return 0;
}