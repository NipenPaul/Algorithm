#include <bits/stdc++.h>
#define int int64_t
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

const int N = (int)1e3+5;
int mat[N][N], n, m;
int maxSum, maxLeft, maxRight, maxUp, maxDown;

void maximumRectangleSum(){
	for(int L = 1; L <= m; L++){
		vector<int> v(n+5, 0);
		for(int R = L; R <= m; R++){
			for(int i = 1; i <= n; i++){
				v[i] += mat[i][R];
			}
			int sum = 0, u = 1, d = 1;
			int curSum = 0, U = 1, D = 1;
			for(int i = 1; i <= n; i++){
				sum += v[i];
				if(sum <= 0){
					sum = 0;
					u = i+1;
				}else if(sum > 0){
					d = i;
				}
				if(sum > curSum){
					curSum = sum;
					U = u;
					D = d;
				}

			}
			if(maxSum < curSum){
				maxUp = U;
				maxDown = D;
				maxSum = curSum;
				maxLeft = L;
				maxRight = R;
			}
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
	maximumRectangleSum();
	CHECK(maxSum);
	CHECK(maxLeft); CHECK(maxRight);
	CHECK(maxUp); CHECK(maxDown);
    return 0;
}

/*
4 5

2  1  -3  -4  5
0  6   3  4  1
2  -2 -1  4  -5
-3  3  1  0  3
*/