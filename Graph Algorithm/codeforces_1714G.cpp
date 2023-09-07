#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;
class Edge{
public:
	int vertex, valA, valB;
};
vector<vector<Edge>> adj;
vector<int> cal, ans;

int binaryUpper(int x){
	int low = 0, high = cal.size() - 1, len = 0;
	while(low <= high){
		int mid = (low + high) / 2;
		if(cal[mid] <= x){
			len = mid;
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return len;
}
void dfs(int u, int a, int b){
	cal.push_back(b);
	int len = binaryUpper(a);
	ans[u] = len;
	for(int i = 0; i < adj[u].size(); i++){
		Edge e = adj[u][i];
		dfs(e.vertex, e.valA + a, e.valB + b);
	}
	cal.pop_back();
}
void solution(int tc){
	int n; cin >> n;
	adj.resize(n+1);
	ans.resize(n+1);
	for(int i = 2; i <= n; i++){
		int v, a, b; cin >> v >> a >> b;
		adj[v].push_back({i, a, b});
	}
	dfs(1, 0, 0);
	for(int i = 2; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	cal.clear(), adj.clear(), ans.clear();
}
int32_t main(){
	Faster;
	int tc = 1; 
	cin >> tc;
	for(int i = 1; i <= tc; i++){
		solution(i);
	}
    return 0;
}
