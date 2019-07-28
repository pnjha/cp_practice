#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,n,k,a,b;
	cin>>t;

	vector<int> w;

	while(t--){
		
		a =0;
		b = 0;
		w.clear();
		
		cin>>n>>k;

		w.resize(n);

		if(k>n/2)
			k = n-k;

		for(int i = 0;i<n;i++)
			cin>>w[i];

		sort(w.begin(),w.end());

		for(int i = 0;i<w.size();i++){
			if(i<k)
				a += w[i];
			else
				b += w[i];
		}

		cout<<abs(a-b)<<"\n";

	}

	return 0;
}
