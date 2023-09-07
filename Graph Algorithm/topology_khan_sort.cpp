#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;

int node, edge;
vector<vector<int>> adj;
vector<int>indegree;

void topologyKhanSort(){
	queue<int> que;
	for(int i = 0; i < node; i++){
		if(indegree[i] == 0) que.push(i);
	}
	int cnt = 0;
	vector<int> order;
	while(!que.empty()){
		cnt++;
		int u = que.front();
		order.push_back(u);
		que.pop();
		for(int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			indegree[v]--;
			if(indegree[v] == 0){
				que.push(v);
			}
		}
	}
	if(cnt != node){
		cout << "There exists a cycle in the graph\n";
	}else{
		cout << "Topological Order: ";
		for(auto it: order){
			cout << it << " ";
		}
		cout << endl;
	}
}

void solution(int tc){
	cin >> node >> edge;
	adj.resize(node);
	indegree.resize(node);
	for(int i = 0; i < edge; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	topologyKhanSort();
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

output Data:
Topological Order: 4 5 2 0 3 1 

*/