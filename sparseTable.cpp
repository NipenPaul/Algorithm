#include <bits/stdc++.h>

using namespace std;

const int LIM = (int) 2e5+2;
int v[LIM], sparse[LIM][25], n, lg[LIM+1];

void sparseTableBuild(){
	lg[1] = 0;
	for (int i = 2; i <= LIM; i++)
    	lg[i] = lg[i/2] + 1;
	for(int i = 1; i <= n; i++)
		sparse[i][0] = v[i];
	int len = lg[n];
	for(int j = 1; j <= len; j++){
		int pw = 1 << j;
		for(int i = 1; i <= n; i++){
			if((i+pw-1) > n)break;
			sparse[i][j] = min(sparse[i][j-1], sparse[i+pw/2][j-1]);
		}
	}
}

int querySparse(int l, int r){
	int len = r - l + 1;
	int base = lg[len];
	int pw = 1 << base;
	return min(sparse[l][base], sparse[r-pw+1][base]);
}

int main(int argc, char const *argv[]){
	int q; cin >> n >> q;
	for (int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	sparseTableBuild();
	while(q--){
		int l, r; cin >> l >> r;
		cout << querySparse(l, r) << '\n';
	}
    return 0;
}
