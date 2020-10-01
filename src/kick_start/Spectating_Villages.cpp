// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edc/000000000018666b

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<ll>> graph;
vector<ll> weight;

ll get_max_weight(ll n){

	set<ll> s;
	vector<pair<ll,ll>> t(n+1,{-1,-1}); //num, val
	map<ll,vector<ll>> mp;
	vector<ll> v,v2;

	ll temp = 0;

	for(int i = 1;i<=n;i++){
	
		v.clear();
		
		temp = weight[i];

		v.push_back(i);

		for(int j = 0;j<graph[i].size();j++){

			temp += weight[graph[i][j]];

			v.push_back(graph[i][j]);
		}

		if(temp > 0){

			bool flag = false;
			ll a=0,b=0;
	
			for(int j = 0;j<=graph[i].size();j++){

				if(j == graph[i].size()){
					if(t[i].second<temp)
						if(t[i].first!=-1){
							a+=abs(t[i].second-temp);
						}else{
							a = temp;
						}
					else
						if(t[i].first!=-1){
							b+=abs(t[i].second-temp);
						}
				}else{
					if(t[graph[i][j]].second<temp){
						if(t[graph[i][j]].first!=-1){
							a+=abs(t[graph[i][j]].second-temp);
						}else{
							a = temp;
						}
					}else{
						if(t[graph[i][j]].first!=-1){
							b+=abs(t[graph[i][j]].second-temp);
						}
					}
				}
			}			

			if(a>b){				

				for(int j = 0;j<=graph[i].size();j++){

					if(j == graph[i].size()){
						t[i] = {i,temp};
					}else{

						t[graph[i][j]] = {i,temp};
					}

					if(flag)
						break;			
				}
			}
		}
	}

	for(int i = 1;i<t.size();i++){
		cout<<t[i].first<<" "<<t[i].second<<"\n";
		if(t[i].first!=-1)
			s.insert(t[i].first);
	}

	temp = 0;
	for(auto x:s){
		
		cout<<x<<" ";

		temp += weight[(x)];
	}

	cout<<endl;

	return temp;
}

int main(){

	freopen("input.txt","r",stdin);

	ll t,n,m,a,b;
	cin>>t;

	while(t--){

		cin>>n;

		graph.clear();
		graph.resize(n+1);

		weight.clear();
		weight.resize(n+1,0);	

		for(int i = 1;i<=n;i++){
			cin>>weight[i];
		}
		
		for(int i = 0;i<n-1;i++){
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		cout<<get_max_weight(n)<<"\n";
	}
	return 0;
}

----------------------------------------------SURAJ---------------------------------------------------------------------------
#include<bits/stdc++.h>

int main(){
    int t;
    cin>>t;
    while(t--){
        int v;
        cin>>v;
        int B[v];
        for(int i=0; i<v; i++){
            cin>>B[i];
        }
        vector<vector<int>> g(v);
        int u, v;
        for(int i=1; i<=v-1; i++){
            cin>>u>>v;
            u--;
            v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
    }
    return 0;
}
