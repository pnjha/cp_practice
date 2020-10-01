int modularExponentiation(int x, int n, int p){
	int res = 1;
	x %= p;

	while(n){

		if(n&1)
			res = (res*x)%p;

		x = (x*x)%p;
		n >>= 1;
	}

	return res;
}

int modularExponentiation(int a, int b, int p){
	int res = 1;
	while(b){
		if(b&1)
			res = (res * a)%p;
		a = (a * a)%p;
		b >>= 1;
	}
	return res;
}