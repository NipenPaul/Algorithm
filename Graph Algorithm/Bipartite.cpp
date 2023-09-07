#include <bits/stdc++.h>
#define CHECK(x)cout<<(#x)<<" = "<<(x)<<'\n';
#define int long long
#define endl '\n'
using namespace std;
bool ok = true;
void isBipartite(int u, int c, vector<vector<int>>&adj, vector<int>&color){
  color[u] = c;
  for(int &v: adj[u]){
    if(color[v] == -1){
      isBipartite(v, c^1, adj, color);
    }else{
      if(color[u] == color[v]){
        ok = false;
      }
    }
  }
}

void solution(){
  int n, m; cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<pair<int, int>> keep;
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    keep.push_back({u, v});
  }
  vector<int> color(n, -1);
  isBipartite(0, 0, adj, color);
  if(!ok){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for(auto &[x, y]: keep){
    cout << (color[x] < color[y]);
  }
  cout << endl;
}
int32_t main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--){
    solution();
  }
  return 0;
}
