#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;
vector<int> adj[N];
int node, edge;
bool vis[N];

void bfs(int u){
	vis[u] = true;
	queue<int> que;
	que.push(u);
	while(!que.empty()){
		u = que.front();
		cout << u << " ";
		que.pop();
		for(auto v: adj[u]){
			if(!vis[v]){
				que.push(v);
				vis[v] = true;
			}
		}
	}
	cout << endl;
}

void solution(int tc){
	cin >> node >> edge;
	for(int i = 1; i <= edge; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
	for(int i = 0; i <= node; i++){
		adj[i].clear();
		vis[i] = false;
	}
}
int32_t main(){
	Faster;
	int tc = 1; 
	//cin >> tc;
	for(int i = 1; i <= tc; i++){
		solution(i);
	}
    return 0;
}
/*
4 4

1 2
1 3
2 4
4 3
*/