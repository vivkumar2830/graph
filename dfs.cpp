#include<bits/stdc++.h>
using namespace std;

void dfs(int node , int vis[] , vector<int> &ls , vector<int> adj[]){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it , vis , ls , adj);
        }
    }
}

vector<int> dfsOfGraph(int V , vector<int> adj[]){
    int vis[V] = {0};
    int start = 0;

    vector<int> ls;

    dfs(start , vis , ls , adj);
    return ls;
}

void addEdge(vector<int> adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector <int> adj[5];
    
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector<int> ans = dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}