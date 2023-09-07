class Solution {
public:
    bool ok;
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int> color(n, -1);
       for(int i = 0; i < n; i++){
           if(color[i] == -1){
               ok = true;
               dfs(i, 0, graph, color);
               if(ok == false){
                   return false;
               }
           }
       } 
       return true;
    }
    void dfs(int u, int c, vector<vector<int>>& graph, vector<int>&color){
        color[u] = c;
        for(int &v: graph[u]){
            if(color[v] == -1){
                dfs(v, c^1, graph, color);
            }else{
                if(color[u] == color[v]){
                    ok = false;
                }
            }
        }
    }
};
