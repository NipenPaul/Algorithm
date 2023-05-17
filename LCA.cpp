#include<bits/stdc++.h>
#define ll long long int
#define limit 100005
using namespace std;

const int N = 1e5+5;
int dist[N];
bool vis[N];

vector<ll> g[limit];
ll height[limit],st[limit][20];

void st_build(ll u,ll p)
{
    for(ll v: g[u])
    {
        if(v==p)  continue;
        height[v] = height[u] + 1;
        st[v][0] = u;
        for(ll j=1; j<20; j++)
        {
            st[v][j] = st[st[v][j-1]][j-1];
        }
        st_build(v,u);
    }
}

ll LCA(ll u, ll v)
{
    if(height[u]>height[v])
        swap(u,v);
    ll dis = height[v]-height[u];
    for(ll j=19; j>=0; j--)
    {
        if( dis&(1<<j) )
            v = st[v][j];
    }
    if(u==v) return u;
    for(ll j=19; j>=0; j--)
    {
        if(st[u][j]!=st[v][j])
        {
            u = st[u][j];
            v = st[v][j];
        }
    }
    return st[u][0];
}

void dfsDist(int src){
    vis[src] = true;
    dist[src] = 0;
    queue<int> que;
    que.push(src);
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int v: g[u]){
            if(vis[v] == false){
                vis[v] = true;
                que.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        for(int i = 0; i <= n; i++){
            g[i].clear();
            dist[i] = 0;
            vis[i] = 0;
            height[i] = 0;
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 20; j++){
                st[i][j] = 0;
            }
        }
        for(int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfsDist(0);
        st_build(0,0);
        while(q--){
            int m; cin >> m;
            vector<int> ar(m);
            for(int i = 0; i < m; i++){
                cin >> ar[i];
                ar[i]--;
            }
            int node = LCA(ar[0], ar[0]);
            for(int i = 0; i < m; i++){
                node = LCA(node, ar[i]);
            }
            int ans = 0;
            for(int i = 0; i < m; i++){
                ans = max(ans, dist[ar[i]]-dist[node]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
