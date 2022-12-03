#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;

void solution(int tc){
	int n; cin >> n;
	stack<pair<int, int>> st;
	vector<int> v(n);
	for(int &x: v) cin >> x;
	int mx = 0;
	for(int i = 0; i < n; i++){
		if(st.empty()){
			st.push({v[i], i});
		}else if(st.top().first < v[i]){
			st.push({v[i], i});
		}else{
			int x, ind = i;
			while(!st.empty() && st.top().first > v[i]){
				x = st.top().first;
				ind = st.top().second;
				mx = max(mx, x*(i-ind));
				st.pop();
			}
			st.push({v[i], ind});
		}
	}
	//CHECK(mx);
	while(!st.empty()){
		int x = st.top().first;
		int ind = st.top().second;
		mx = max(mx, x*(n-ind));
		st.pop();
	}
	cout << "Case " << tc << ": ";
	cout << mx << endl;
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