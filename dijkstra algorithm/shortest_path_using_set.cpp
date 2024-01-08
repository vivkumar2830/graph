#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
    set<pair<int,int>> st;
    vector<int> dist(V);
    for(int i = 0 ; i < V ; i++){
        dist[i] = 1e9;
    }
    st.insert({0,S});
    dist[S] = 0;

    while(!st.empty()){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]){
            int v = it[0];
            int w = it[1];

            if(dis + w < dist[v]){
                if(dist[v] != 1e9){
                    st.erase({dist[v] , v});
                }
                dist[v] = dis + w;
                st.insert({dist[v] , v});
            }
        }
    }
    return dist;
}

int main(){
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    //int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}