#include<bits/stdc++.h>
using namespace std;

bool detect(int src , int vis[] , vector<int> adj[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src , -1});

    while( !q.empty() ){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it , node});
            }
            else if( it != parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V , vector<int> adj[]){
    int vis[V] = {0};

    for(int i = 0 ; i < V ; i++){
        if( !vis[i] ){
            if(detect(i , vis , adj)) return true;
        }
    }
    return false;
}

int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}