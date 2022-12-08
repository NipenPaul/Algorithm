long long myPow(int base, int power){ 
	long long answer = 1;
	while(power > 0){
	 	if((power & 1)){
	 		answer = answer * base;
	 	} 
	 	base = base * base;
	 	power = power >> 1LL;
	} 
	return answer; 
}
