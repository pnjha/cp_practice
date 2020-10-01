#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
const int MAXN = 55;
const int MAXS = 6000;
ll dp[MAXN][MAXS][MAXN];
ll n,k;

ll solve(int idx, int sum, int count, int mins, vector<int>& a)
{
	if (idx < -1) 
		return 0; 
	if (idx == -1) {
		if (count == k && sum == mins)
			return 1;
		else
		    return 0;
	}
	if (dp[idx][sum][count] != -1)
		return dp[idx][sum][count];
	dp[idx][sum][count] = solve(idx-1,sum,count,mins,a)+solve(idx-1,sum+a[idx],count+1,mins,a);
	return dp[idx][sum][count];
}

int main() {

	freopen("input.txt","r",stdin);

	int t;
	cin >> t;
	
	while(t--)
	{
	    memset(dp,-1,sizeof dp);
	    cin >> n >> k;
	    vector<int> a(n);
	    vector<int> b(n);

	    
	    for(int i=0; i<n; i++)
	        cin >> a[i];
	   	b = a;
	    sort(a.begin(),a.end());
	    int mins = 0;
	    for(int i=0; i<k; i++)
	        mins+=a[i];
	    //cout << mins << endl;
	    cout << solve(n-1,0,0,mins, b) << endl;
	}
	return 0;
}


// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

/*
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
*/