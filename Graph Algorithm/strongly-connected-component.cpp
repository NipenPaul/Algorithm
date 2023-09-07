#include <bits/stdc++.h>
#define CHECK(x)cout<<(#x)<<" = "<<(x)<<'\n';
#define int long long
#define endl '\n'
using namespace std;

const int N = 1e5+2;
int node, edge;

vector<int> adj[N], adjR[N];
vector<bool> vis(N);
stack<int> st;

void dfs(int u){
  vis[u] = true;
  for(int &v: adj[u]){
    if(!vis[v]){
      dfs(v);
    }
  }
  st.push(u);
}
void dfs2(int u){
  cout << u << " ";
  vis[u] = true;
  for(int &v: adjR[u]){
    if(!vis[v]){
      dfs2(v);
    }
  }
}
void scc(){
  for(int i = 0; i < node; i++){
    if(!vis[i]){
      dfs(i);
    }
  }
  vis = vector<bool>(node+1, false);
  cout << "Component are:\n";
  while(!st.empty()){
    int u = st.top();
    st.pop();
    if(!vis[u]){
      dfs2(u);
      cout << endl;
    }
  }
}
void solution(){
  cin >> node >> edge;
  for(int i = 0; i < node; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adjR[v].push_back(u);
  }
  scc(); 
}
int32_t main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int t = 1; //cin >> t;
  while(t--){
    solution();
  }
  return 0;
}

/*
input data:
9 10

0 1
1 2
2 3
3 0
2 4
4 5
5 6
6 4
7 8
7 6

*/
