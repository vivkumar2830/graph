#include<bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K){
    vector<pair<int,int>> adj[n];
    for(auto it : flights){
        adj[it[0]].push_back({it[1] , it[2]});
    }

    queue<pair<int, pair<int,int>>> q;
    q.push({0 , {src , 0}});

    vector<int> dist(n , 1e9);
    dist[src] = 0;

    while( !q.empty() ){
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(stops > K){
            continue;
        }
        for(auto it : adj[node]){
            int v = it.first;
            int w = it.second;

            if(cost + w < dist[v] && stops <= K){
                dist[v] = cost + w;
                q.push({stops + 1 , {v , dist[v]}});
            }
        }
    }
    if(dist[dst] == 1e9){
        return -1;
    }
    return dist[dst];
}

int main(){
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    int ans = CheapestFLight(n, flights, src, dst, K);

    cout << ans;
    cout << endl;

    return 0;
}