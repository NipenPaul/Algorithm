int dp[N];//p[]=profit array, w[]=weight array, mxW=Weight
int knapsack(vector<int>&w, vector<int>&p, int mxW, int n){
	for(int i = 0; i < n; i++){
		for(int j = mxW; j >= 0; j--){
			if(j < w[i]) continue;
			dp[j] = max(dp[j], p[i]+dp[j-w[i]]);
		}
	}
	return dp[mxW];
}