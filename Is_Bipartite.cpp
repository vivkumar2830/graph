#include<bits/stdc++.h>
using namespace std;

bool dfs(int node , int col , int color[] , vector<vector<int>>& graph){
    color[node] = col;
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(dfs(it , !col , color , graph) == false){
                return false;
            }
        }
        if(color[it] == col){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    int color[V];
    for(int i = 0 ; i < V ; i++){
        color[i] = -1;
    }

    for(int i = 0 ; i < V ; i++){
        if(color[i] == -1){
            if(dfs(i , 0 , color , graph) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout<<isBipartite(graph);


    return 0;
}