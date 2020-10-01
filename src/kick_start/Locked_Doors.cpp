// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff08/0000000000386d5c

#include<bits/stdc++.h>
#define  ll long long int

using namespace std;

/*
90	30	40	60
0	1	2	3	4 ->i,j
*/

void precompute(vector<vector<ll>>& dp,vector<ll>& arr){
	
	ll n = arr.size()+1;

	for(int i = 0;i<n;i++){
		ll step = 0,j = 0;
		vector<bool> visited(n,false);
		dp[i][step] = j;
		visited[i] = true;
		while(step<n){
			
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("input.txt","r",stdin);

	ll t;
	cin>>t;

	for(int k = 0;k<t;k++){

		ll n,q,a,b;
		cin>>n>>q;

		vector<ll> arr(n-1);
		vector<ll> ans(q);
		vector<vector<ll>> dp(n,vector<ll>(n,0));

		for(int i = 0;i<n-1;i++) cin>>arr[i];

		precompute(dp,arr);

		for(int i = 0;i<dp.size();i++){
			for(int j = 0;j<dp[0].size();j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}

		for(int i = 0;i<q;i++){
			cin>>a>>b;
			ans.push_back(dp[a-1][b-1]);
		}

		cout <<"Case #" << k <<": ";
		for(int i = 0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}


}


/*
2
5 4
90 30 40 60
3 4
3 1
1 5
4 3
10 2
6 2 4 5 9 30 7 1 8
6 8
6 8
*/


#include <bits/stdc++.h>
using namespace std;

int t, n, q;
vector<int> D;
vector<vector<int>> A;

void process(int &start, int left, int curr, int right){
    if(curr == left)
        left--;
    if(curr == right)
        right++;
    
    A[start].push_back(curr);
    
    if( (A[start].size() == n)) //(left < 1 and right > n) or
        return;
    // cout<<"left: "<<left<<" curr: "<<curr<<" right: "<<right<<endl;
    
    int x = (left < 1) ? INT_MAX : D[left];
    int y = (right > n) ? INT_MAX : D[right-1];
    
    // cout<<"left door: "<<x<<" right door: "<<y<<endl;
    if(x < y){
        process(start, left, left, right);
    }
    else{
        process(start, left, right, right);
    }
}

int main() {
    cin>>t;
    for(int tc = 1; tc<=t; tc++){
        cin>>n>>q;
        
        D.resize(n);
        for(int i=1; i<n; i++){
            cin>>D[i];
        }
        
        A.resize(n+1);
        for(int start=1; start <= n; start++){
            // cout<<"starting from "<<start<<endl;
            process(start, start-1, start, start+1);    
        }
        
        // cout<<"Processed table is: "<<endl;
        // for(int i=1; i<=n; i++){
        //     for(int j=0; j<A[i].size(); j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> ans;
        int s,k;
        while(q--){
            cin>>s>>k;
            ans.push_back(A[s][k-1]);
        }
        cout<<"Case #"<<tc<<": ";
        for(int x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}