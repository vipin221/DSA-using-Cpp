#include<iostream>

#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<stack>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>>adj;
    void addEdge(int u, int v , int wt, bool dir){
        adj[u].push_back({v,wt});
        if(dir == 0){
            adj[v].push_back({u, wt});
        }

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
     void DijkstraAlgo(int n, int src, int dest){
        vector<int>dist(n+1, INT_MAX);
        set<pair<int, int>> st; // set<pair<distance,node>>st; -> coz i want it to be sorted wrt distance
        // initial state
        st.insert({0,src});

        while(!st.empty()){
            auto topPair = *st.begin();
            int topNode = topPair.second;
            int topDist = topPair.first;
            st.erase(st.begin());

            for(auto nbrPair : adj[topNode]){
                int nbrDist = nbrPair.second;
                int nbrNode = nbrPair.first;

                if(nbrDist + topDist < dist[nbrNode]){
                    // if element is already present in set find and erase it
                    auto previousElement = st.find({dist[nbrNode],nbrNode});
                    if(previousElement != st.end()){
                        st.erase(previousElement);
                    }

                    //update st and dist;
                    dist[nbrNode] = nbrDist + topDist;
                    st.insert({dist[nbrNode], nbrNode});
                }


            }
        }

        cout<<"the sortest distance from"<< src <<" to " << dest<< " is " << dist[dest];

    }

};


int main(){
    Graph g;

    g.addEdge(6,5,9,0);
    g.addEdge(6,3,2,0);
    g.addEdge(6,1,14,0);
    g.addEdge(5,4,6,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,2,10,0);
    g.addEdge(3,4,11,0);
    g.addEdge(1,2,7,0);
    g.addEdge(4,2,15,0);
    g.printAdj();

    g.DijkstraAlgo(6,6,4);


 
    return 0;
}