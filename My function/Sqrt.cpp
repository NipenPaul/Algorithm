template<typename T>
T mySqrt(T n){
	T lo = 0.0, hi = (T)1e9+1, ans = 0.0;
	for(int i = 0; i < 100; i++){
		T mid = (lo+hi)/2.0;
		if(mid*mid <= n){
			ans = mid;
			lo = mid;
		}else{
			hi = mid;
		}
	}
	return ans;
}
