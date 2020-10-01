// https://cses.fi/problemset/task/1713

//count divisors sieve prime numbers

#include<bits/stdc++.h>
#define ll long long int
#define SIZE 1000004

using namespace std;

//gives TLE on large testcase
inline ll count_divisors(ll n){

	if(n==1)
		return 1;

	ll left = 1, max_left = int(ceil(sqrt(n))), right = n;
	ll cnt = 0;

	while(left<right && left<=max_left){

		
		if(n%left==0){

			right = n/left;
			
			// cout<<left<<" "<<right<<"\n";

			if(right!=left)
				cnt += 2;
			else
				cnt++;
		}
		left++;
	}

	return cnt;
}

vector<ll> psf;

void sieve(){

	ll prime[SIZE];

	psf.clear();
	
	for(int i = 0;i<SIZE;i++)
		prime[i] = 1;
	
	for(int i = 4;i<SIZE;i+=2)
		prime[i] = 0;


	for(int i = 2;i<SIZE;i++){

		if(prime[i] == 1){
			psf.push_back(i);
		}

		for(int j = 0;j<psf.size()&&(i*psf[j])<SIZE;j++){
			prime[i*psf[j]] = 0;
		}
	}
} 

ll count_divisors_sieve(ll n){

	if(n==1)
		return 1;

	ll ans = 1,cnt = 0;

	for(auto a : psf){

		cnt = 0;

		while((n%a)==0){

			cnt++;
			n = n/a;
		}

		cnt++;

		ans = ans * cnt;

		if(a*a>=n){
			ans *= 1+(n>1);
			break;
		}
	}

	return ans;
}



// int main(){

// 	// ios_base::sync_with_stdio(false);
// 	// cin.tie(nullptr);

// 	// cout<<"started\n";

// 	sieve();

// 	// cout<<"ended\n";

// 	ll t,n;

// 	cin>>t;

// 	while(t--){

// 		cin>>n;

// 		cout<<count_divisors_sieve(n)<<"\n";
// 	}

// 	return 0;
// }


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int arr[SIZE];

	memset(arr,0,sizeof(arr));

	for(int i = 2;i<SIZE;i++){
		for(int j=i;j<SIZE;j=j+i)
			arr[j]++;
	}

	ll t,n;

	cin>>t;

	while(t--){

		cin>>n;

		cout<<arr[n]+1<<"\n";
	}

	return 0;
}