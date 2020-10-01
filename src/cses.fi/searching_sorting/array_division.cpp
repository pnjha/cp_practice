#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	ll n,k,sum=0;
	cin>>n>>k;

	vector<ll> arr(n);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}

	// sort(arr.begin(),arr.end());

	// for(int i=0;i<arr.size();i++)
	// 	cout<<arr[i]<<" ";
	// cout<<"\n";

	// cout<<sum<<"\n";

	ll max_val = INT_MIN,temp = 0;

	for(int i = 0;i<arr.size();i++){

		if(temp<ceil(sum/k)){

			temp += arr[i];

		}else{
			// cout<<temp<<"\n";
			if(temp>max_val)
				max_val = temp;

			temp = arr[i];
		}

	}

	if(temp>max_val)
		max_val = temp;

	cout<<max_val<<"\n";

	return 0;
}
