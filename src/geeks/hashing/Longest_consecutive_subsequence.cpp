#include<bits/stdc++.h>

using namespace std;

int main(){

	int t,n,temp,i,val=-1,cnt = 0;

	cin>>t;

	unordered_set<int> s;
	unordered_map<int,int> m;

	while(t--){

		cin>>n;

		s.clear();
		m.clear();
		
		for(int i = 0;i<n;i++){
			cin>>temp;
			s.insert(temp);
		}

		
		val=-1;
		cnt = 0;

		while(!s.empty()){

			auto itr = s.begin();
			val = *itr;
			cnt = 1;

			while(!s.empty() && s.find(*itr-cnt)!=s.end()){
				s.erase(*itr-cnt);
				cnt++;
			}

			if(m.find(*itr-cnt)!=m.end()){
				cnt += m[*itr-cnt];
			}

			m[val] = cnt;
			s.erase(val);
		}

		int max_val = INT_MIN;
		for(auto itr = m.begin();itr!=m.end();itr++)
			if(itr->second > max_val)
				max_val = itr->second;

		cout<<max_val<<"\n";
	}

	return 0;
}






