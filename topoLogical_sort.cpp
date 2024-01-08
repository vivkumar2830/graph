#include<bits/stdc++.h>
using namespace std;

// using --------------------------DFS-----------------------
// void dfs(int node , int vis[] , vector<int> adj[] , stack<int> &st){
//     vis[node] = 1;
//     for(auto it : adj[node]){
//         if(!vis[it]){
//             dfs(it , vis , adj , st);
//         }
//     }
//     st.push(node);
// }

// vector<int> topoSort(int V, vector<int> adj[]){
//     // code here
//     int vis[V] = {0};
//     stack<int> st;
//     for(int i = 0 ; i < V ; i++){
//         if(!vis[i]){
//             dfs(i , vis , adj , st);
//         }
//     }
//     vector<int> ans;
//     while(!st.empty()){
//         ans.push_back(st.top());
//         st.pop();
//     }
//     return ans;
// }

// ---------------------------------- BFS --------------------------------
vector<int> topoSort(int V, vector<int> adj[]){
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

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    return ans;
    
}

int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	
	vector<int> ans = topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;
    return 0;
}