#include <bits/stdc++.h>
using namespace std;
#define CHECK(x)cout<<(#x)<<" is "<<(x)<<'\n';
#define int long long

const int N = 1e5+2;
vector<int> adj[N];
int ar[N], parent[N];
long long preSum[N];

void dfs(int u, int pa){
  preSum[u] = ar[u];
  for(int &v: adj[u]){
    if(pa == v) continue;
    dfs(v, u);
    preSum[u] += preSum[v];
  }
}
void solution(){
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> ar[i];
  }
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  for(int i = 1; i <= n; i++){
    CHECK(i);
    CHECK(preSum[i]);
  }
}
int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  //cin >> t;
  while(t--){
    solution();
  }
}
