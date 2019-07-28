#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll max_histogram_area(vector<ll>& arr){

	ll ans = INT_MIN;

	stack<int> s;

	int i = 0,top;

	while(i < arr.size()){

		if(s.empty() || arr[s.top()] < arr[i]){
			s.push(i);
			i++;
		
		}else{

			top = s.top();
			s.pop();

			if(s.empty()){

				ans = max(ans, arr[top] * i);

			}else{

				ans = max(ans, arr[top] * (i - s.top() - 1));

			}
		}
	}

	while(!s.empty()){

		top = s.top();
		s.pop();

		if(s.empty()){

			ans = max(ans, arr[top] * i);

		}else{

			ans = max(ans, arr[top] * (i - s.top() - 1));

		}
	}

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	vector<ll> arr(n,0);

	for(int i = 0;i<arr.size();i++)
		cin>>arr[i];

	cout<<max_histogram_area(arr)<<"\n";

	return 0;
}
