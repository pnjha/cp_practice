// https://codeforces.com/contest/808
// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int main(){

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	ll n,k=0;
// 	cin>>n;

// 	vector<ll> arr(n,0);
// 	map<ll,int> suffix;
// 	map<ll,int> prefix;

// 	for(int i = 0;i<n;i++){
// 		cin>>arr[i];
// 		k += arr[i];
// 	}

// 	if(k%2 == 1 || n == 1){
// 		cout<<"NO\n";
// 		return 0;
// 	}

// 	k = k/2;
// 	ll sum = 0;
// 	prefix[0] = 1;

// 	for(int i = 0;i<n;i++){
// 		prefix[arr[i]]++;
// 		sum += arr[i];
// 		if(prefix[(sum - k)]>0){
// 			cout<<"Yes\n";
// 			return 0;
// 		}
// 	}

// 	sum = 0;
// 	suffix[0] = 1;

// 	for(int i = n-1;i>=0;i--){
// 		suffix[arr[i]]++;
// 		sum += arr[i];
// 		if(suffix[(sum - k)]>0){
// 			cout<<"Yes\n";
// 			return 0;
// 		}
// 	}

// 	cout<<"NO\n";

// 	return 0;
// }

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	ll n,k=0;
	cin>>n;
 
	vector<ll> arr(n,0);
	map<ll,int> suffix;
	map<ll,int> prefix;
 
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		suffix[arr[i]] = i;
		k += arr[i];
	}
 
	for(int i = n-1;i>=0;i--){
		prefix[arr[i]] = i;
	}
 
	if(k%2 == 1){
		cout<<"NO\n";
		return 0;
	}
 
	k = k/2;
 
	ll sum = 0;
 
	for(int i = 0;i<n;i++){
 
		if(arr[i] == k){
			cout<<"YES\n";
			return 0;
		}
 
		sum += arr[i];
 
		if(sum == k){
			cout<<"YES\n";
			return 0;
		}else if(sum < k){
			if(suffix.find((k - sum)) != suffix.end() && suffix[(k - sum)]>i){
				cout<<"YES\n";
				return 0;
			}
		}else{
			if(prefix.find((sum - k)) != prefix.end() && prefix[(sum - k)]<i){
				cout<<"YES\n";
				return 0;
			}
		}
 
	}
 
 
	cout<<"NO\n";
 
	return 0;
}