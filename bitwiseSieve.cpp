#include <bits/stdc++.h>

using namespace std;

bool ifnotPrime(int prime[], int x){
	return (prime[x/64] & (1 << ((x >> 1) & 31)));
}

void makeComposite(int prime[], int x){
	prime[x/64] |= (1 << ((x >> 1) & 31));
}

void bitwiseSieve(int n){
	int prime[n/64];
	for(int i = 3; i * i <= n; i++){
		if(!ifnotPrime(prime, i)){
			for(int j = i * i, k = i << 1; j < n; j += k){
				makeComposite(prime, j);
			}
		}
	}
	cout << 2 << " ";
	for(int i = 3; i <= n; i += 2){
		if(!ifnotPrime(prime, i)){
			cout << i << " ";
		}
	}
	cout << endl;
}
int main(int argc, char const *argv[])
{
	bitwiseSieve(29);
	return 0;
}