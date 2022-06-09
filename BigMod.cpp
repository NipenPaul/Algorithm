ll BigMod(ll base, ll pw, ll Mod){
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
