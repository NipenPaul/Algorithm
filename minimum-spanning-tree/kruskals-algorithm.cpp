class Pair{
public:
    int u, v, cost;
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Pair> edges;
        //try to create a complete graph
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({i, j, dis});
            }
        }
        // try to create a tree with minimum cost
        int ans = minimumSpanningTree(n, edges);
        return ans;
    }
    int minimumSpanningTree(int n, vector<Pair>&edges){
        // sort the all edges with cost
        sort(edges.begin(), edges.end(), [&](const auto &a, const auto &b){
            return a.cost < b.cost;
        });
        vector<int> parent(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        // dsu definition, find
        function<int(int)> find = [&](int x)->int{
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            if(find(edges[i].u) != find(edges[i].v)){
                // union
                parent[parent[edges[i].u]] = parent[edges[i].v];
                ans += edges[i].cost;
            }
        }
        return ans;
    }
};