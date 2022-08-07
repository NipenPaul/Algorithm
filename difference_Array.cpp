/* I can implement a program that can given O(1) 
for all range query update left to right.
it's technic called to difference array*/

/*
Given array:
n = 9
array = [2 3 4 7 3 2 1 6 7]
q = 3
l r value
1 7 5
3 5 3
5 8 2

Main input:
9
2 3 4 7 3 2 1 6 7
3
1 7 5
3 5 3
5 8 2

output:
Final Updated Array:
7 8 12 15 13 9 8 8 7
*/

#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#define Faster ios::sync_with_stdio(false);cin.tie(nullptr);
#define CHECK(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

const int N = (int)1e5+5;

void solution(int tc){
	int n; cin >> n;
	std::vector<int> v(n+5, 0);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	vector<int> diffA(n+5, 0);
	diffA[1] = v[1];
	for(int i = 2; i <= n; i++){
		diffA[i] = v[i] - v[i-1];
	}
	int q; cin >> q;
	while(q--){
		int l, r, val; cin >> l >> r >> val;
		diffA[l] += val;
		diffA[r+1] -= val;
	}
	vector<int> finalA(n+5, 0);
	finalA[1] = diffA[1];
	for(int i = 2; i <= n; i++){
		finalA[i] = finalA[i-1] + diffA[i];
	}
	cout << "Final Updated Array:\n";
	for(int i = 1; i <= n; i++){
		cout << finalA[i] << " ";
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
