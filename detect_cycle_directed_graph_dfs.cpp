#include<bits/stdc++.h>
using namespace std;

// ------------------------- DFS ---------------------------------
// bool dfs(int node , int vis[] , int pathVis[], vector<int> adj[]){
//     vis[node] = 1;
//     pathVis[node] = 1;
//     for(auto it: adj[node]){
//         if(!vis[it]){
//             if(dfs(it , vis , pathVis , adj) == true){
//                 return true;
//             }
//         }
//         if(pathVis[it]){
//             return true;
//         }
//     }
    
    
//     pathVis[node] = 0;
//     return false;
// }

// bool isCyclic(int V, vector<int> adj[]) {
//     // code here
//     int vis[V] = {0};
//     int pathVis[V] = {0};
    
//     for(int i = 0 ; i < V ; i++){
//         if(!vis[i]){
//             if(dfs(i , vis, pathVis , adj) == true){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// -------------------------------------  BFS   -----------------------------------------
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    int indegree[V] = {0};
    for(int i = 0 ; i < V ; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int c = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        c++;

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if( c == V){
        return false;
    }
    else{
        return true;;
    }
}

int main(){
    vector<int> adj[6] = {{}, {2}, {3}, {4, 5}, {2}, {}};
	int V = 6;
	bool ans = isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";
    return 0;
}