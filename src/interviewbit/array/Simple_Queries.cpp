// https://www.interviewbit.com/problems/simple-queries/

#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define SIZE 100007

using namespace std;

int debug = 0;

vector<ll> div_prod;

void generate_divisor_product(ll n){

	div_prod.clear();
	div_prod.resize(n+1,1);

	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j+=i){
			div_prod[j] = (div_prod[j]*i)%MOD;			
		}
	}
}

bool cmp(pair<ll,ll>p1,pair<ll,ll>p2){

	if(p2.first<p1.first)
		return true;

	if(p2.first == p1.first){
		if(p2.second < p1.second){
			return true;
		}
	}
	return false;
}

vector<ll> solve(vector<ll>& A, vector<ll>& B){

	ll n = A.size();

	stack<ll> s;

	//next greater left
	vector<ll> greater_left(n);
	
	s.push(0);
	greater_left[0] = -1;
	int i = 1;

	while(!s.empty()&&i<n){
		while(!s.empty()&& A[s.top()]<=A[i]){
			s.pop();
		}
		if(s.empty()) greater_left[i] = -1;
		else greater_left[i] = s.top();
		s.push(i);
		i++;
	}

	while(!s.empty())
		s.pop();
	
	//next greater right
	vector<ll> greater_right(n);

	s.push(n-1);
	greater_right[n-1] = n;
	i = n-2;

	while(!s.empty()&&i>=0){
		while(!s.empty()&& A[s.top()]<=A[i]){
			s.pop();
		}
		if(s.empty()) greater_right[i] = n;
		else greater_right[i] = s.top();
		s.push(i);
		i--;
	}

	while(!s.empty())
		s.pop();
	
	if(debug){
		for(int i = 0;i<greater_left.size();i++){
			cout<<greater_left[i]<<" ";
		}cout<<"\n";

		for(int i = 0;i<greater_right.size();i++){
			cout<<greater_right[i]<<" ";
		}cout<<"\n";
	}

	vector<pair<ll,ll>> arr(n);

	if(debug){
		ll max_ele = *max_element(A.begin(),A.end());
		for(int i = 1;i<=max_ele;i++)
			cout<<div_prod[i]<<" ";
		cout<<"\n";
	}

	for(int i = 0;i<n;i++){
		arr[i] = {div_prod[A[i]],((i-greater_left[i])%MOD*(greater_right[i]-i)%MOD)%MOD};
	}

	if(debug){
		for(int i = 0;i<arr.size();i++){
			cout<<arr[i].first<<" "<<arr[i].second<<" ";
		}cout<<"\n";
	}

	sort(arr.begin(),arr.end(),cmp);

	if(debug){
		for(int i = 0;i<arr.size();i++){
			cout<<arr[i].first<<" "<<arr[i].second<<" ";
		}cout<<"\n";
	}

	vector<ll> psum(n);

	for(int i = 0;i<n;i++){
		if(i == 0)
			psum[i] = arr[i].second;
		else
			psum[i] = (psum[i-1] + arr[i].second)%MOD;
	}

	if(debug){
		for(int i = 0;i<psum.size();i++){
			cout<<psum[i]<<" ";
		}cout<<"\n";
	}

	vector<ll> ans;
	psum[n-1]++;

	for(int i = 0;i<B.size();i++){
		ans.push_back(arr[lower_bound(psum.begin(),psum.end(),B[i])-psum.begin()].first);
	}

	return ans;
}

int main(){

	vector<ll> A = {39,99,70,24,49,13,86 ,43, 88, 74, 45 ,92, 72, 71, 90, 32 ,19,
	 76, 84, 46 ,63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45};
	vector<ll> B = {1221,360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838};

	ll max_ele = *max_element(A.begin(),A.end());

	generate_divisor_product(max_ele+7);
	vector<ll> C = solve(A,B);

	for(int i = 0;i<C.size();i++)
		cout<<C[i]<<" ";
	cout<<"\n";

	return 0;
}


 //7569 1000000000 1000000000 440996283 778688 1000000000 1000000000 1000000000 1000000000 1000000000 83 1000000000 440996283 778688 3364 59969536 1000000000 1000000000 7569 1000000000 970299 1000000000 59969536 1000000000 970299
 //970299 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 970299 1000000000 1000000000 1000000000 970299 1000000000 1000000000 1000000000 970299 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000