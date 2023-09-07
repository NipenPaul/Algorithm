class Solution {
public:
    int ans = INT_MAX;
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n+1];
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i < n; i++){
            bfs(i, adj, n);
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
    void bfs(int src, vector<int> adj[], int n){
        vector<int> dist(n+1, (int)1e9);
        vector<int> parent(n+1, -1);
        queue<int> que;
        que.push(src);
        dist[src] = 0;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int &child: adj[node]){
                if(dist[child] == (int)1e9){
                    dist[child] = dist[node]+1;
                    parent[child] = node;
                    que.push(child);
                }else if(parent[node] != child && parent[child] != node){
                    ans = min(ans, dist[node]+dist[child]+1);
                }
            }
        }
    }
};
