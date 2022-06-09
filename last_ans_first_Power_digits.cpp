ll lastDigits(ll base, ll pw, ll Mod){
	// Last 3 digit just MOD = 1000
	ll ans = 1;
	while(pw > 0){
		if(pw & 1){
			ans = (ans * base) % Mod;
		}
		pw >>=1L;
		base = (base*base) % Mod;
	}
	return ans;
}
ll firstDigits(ll n, ll k){
	long double power;
	power = (double)k * log10(n);
	//cout << power - floor(power) << endl;
	ll ans = pow(10, power - floor(power)) * 100.0;
	return ans;
}
