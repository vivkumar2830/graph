#include<bits/stdc++.h>
using namespace std;

bool detect(int node ,int parent , int vis[] , vector<int> adj[]){
    vis[node] = 1;

    for(auto it : adj[node]){
        if( !vis[it] ){
            if(detect(it , node , vis , adj) == true){
                return true;
            }
        }
        else if( it != parent){
            return true;
        }
    }
    
    return false;
}

bool isCycle(int V , vector<int> adj[]){
    int vis[V] = {0};

    for(int i = 0 ; i < V ; i++){
        if( !vis[i] ){
            if(detect(i , -1 , vis , adj) == true) return true;
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