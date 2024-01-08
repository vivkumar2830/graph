#include<bits/stdc++.h>
using namespace std;

// bool dfs(int node , vector<int> &vis, vector<int> &pathVis, vector<vector<int>>& graph,vector<int> &check){
//     vis[node] = 1;
//     pathVis[node] = 1;
//     check[node] = 0;
//     for(auto it: graph[node]){
//         if(!vis[it]){
//             if(dfs(it , vis , pathVis , graph , check) == true){
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         if(pathVis[it]){
//             check[node] = 0;
//             return true;
//         }
//     }
    
    
//     pathVis[node] = 0;
//     check[node] = 1;
//     return false;
// }

// vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//     int V = graph.size();
//     vector<int> vis(V , 0);
//     vector<int> pathVis(V , 0);
//     vector<int> check(V , 0);
//     // int vis[V] = {0};
//     // int pathVis[V] = {0};
//     // int check[V] = {0};
//     vector<int> safeNode;
    
//     for(int i = 0 ; i < V ; i++){
//         if(!vis[i]){
//             dfs(i , vis, pathVis , graph, check);
//         }
//     }
//     for(int i = 0 ; i < V ; i++){
//         if(check[i] == 1){
//             safeNode.push_back(i);
//         }
//     }
//     return safeNode;
// }


// int main(){
//     vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
//     vector<int> ans = eventualSafeNodes(graph);

//     for(int i = 0 ; i < ans.size() ; i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }



//-------------------------  using bfs  -------------------------------------
vector<int> eventualSafeNodes(int V , vector<int> adj[]){
    vector<int> adjRev[V];
    int indegree[V] = {0};

    for(int i = 0 ; i < V ; i++){
        for(auto it : adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for(int i = 0 ; i < V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto it : adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

    reverse(ans.begin() , ans.end());
    return ans;
}

int main() {
	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	vector<int> safeNodes = eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}