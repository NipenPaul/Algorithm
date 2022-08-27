#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+2;
int mat[N][N], n, m, cum[N][N];

void cumalativeSum(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cum[i][j]=cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+mat[i][j];
		}
	}
}


int32_t main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mat[i][j];
		}
	}
	cumalativeSum();
	int q; cin >> q;
	while(q--){
		int a, b, c, d; 
		cin >> a >> b >> c >> d; //(a, b) to (c, d)
		cout << cum[c][d]-cum[a-1][d]-cum[c][b-1]+cum[a-1][b-1] << endl;
	}
    return 0;
}
/*
Input:
5 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
1
3 2 4 3
Output: 
10
*/