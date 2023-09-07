/*
Implementation Topological Sort using dfs with discovering
and finishing time..
*/
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;

const int WHITE = 1;
const int GRAY = 2;
const int BLACK = 3;

int node, edge;
vector<vector<int>> adj;
vector<int> color, startTime, finishTime;
deque<int> deq;
int times = 1;

void topologySort_dfs(int u){
	startTime[u] = times++;
	color[u] = GRAY;
	for(int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if(color[v] == GRAY){
			cout << "There exist a cycle\n";
			return;
		}
		if(color[v] == WHITE){
			topologySort_dfs(v);
		}
	}
	color[u] = BLACK;
	finishTime[u] = times++;
	deq.push_front(u);
}

void dfs(){
	for(int i = 0; i < node; i++){
		color[i] = WHITE;
	}
	for(int i = 0; i < node; i++){
		if(color[i] == WHITE){
			topologySort_dfs(i);
		}
	}
}
void solution(int tc){
	cin >> node >> edge;
	adj.resize(node);
	color.resize(node);
	startTime.resize(node);
	finishTime.resize(node);

	for(int i = 0; i < edge; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	dfs();
	if(deq.size() != node){
		return;
	}
	cout << "Following Topological Sort: \n";
	for(auto it: deq){
		cout << it << " ";
	}
	cout << endl;
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
input Data:
6 6

5 2
5 0
4 0
4 1
2 3
3 1

Output Data:
Following Topological Sort: 
5 4 2 3 1 0 

*/