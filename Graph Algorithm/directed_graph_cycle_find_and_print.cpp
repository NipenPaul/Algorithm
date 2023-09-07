#include <bits/stdc++.h>
#define CHECK(x)cout<<(#x)<<" = "<<(x)<<'\n';
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+2;
vector<int> adj[N];
int path[N];
bool vis[N];
bool ok = false;
void bfs(int src){
  vis[src] = true;
  queue<int> que;
  que.push(src);
  path[src] = 0;
  while(!que.empty()){
    int u = que.front();
    que.pop();
    for(int &v: adj[u]){
      if(!vis[v]){
        vis[v] = true;
        que.push(v);
        path[v] = u;
      }else if(path[v] != u){
       // cout << "ex"; path[u] != v &&
        path[v] = u;
        int tem = u;
        vector<int> ve;
        while(path[tem] != u){
          ve.push_back(path[tem]);
          tem = path[tem];
        }
        ve.push_back(u);
        cout << ve.size() << endl;
        for(int i = ve.size()-1; i >= 0; i--){
          cout << ve[i] << " ";
        }
        cout << endl;
        ok = true;
        return;
      }
    }
  }
}
void solution(){
  int n; cin >> n;
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    adj[i].push_back(x);
  }
  for(int i = 1; i <= n; i++){
    if(ok) return;
    if(!vis[i]){
      bfs(1);
    }
  } 
}
int32_t main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--){
    solution();
  }
  return 0;
}
