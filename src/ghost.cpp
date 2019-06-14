#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
vector<int>submask[22];
bool vis[1<<22];
ll dp[1<<22];
int N;
ll rec(int mask){
    if(mask==(1<<(N+1))-2) return 1;
    if(vis[mask]) return dp[mask];
    vis[mask] = 1;
    ll &ret = dp[mask];
    ret=0;
    int x;
    for(int i=1;i<=N;i++){
        if(!(mask&(1<<i))){
            bool ok = 1;
            rep(j,submask[i].size()){
                x = submask[i][j];
                if(!(mask&(1 << x ))) ok=0;
            }
            if(ok){
                ret += rec(mask|(1<<i));
            }
        }
    }
    return ret;
}
int main(){
    
    for(int i=1;i<=20;i++){
        for(int j=i-1;j>=1;j--){
            if( (i&j)==j ) submask[i].pb(j);
        }
    }

    cin >> N;
    
    cout<<rec(0);

    for(int i=0;i<22;i++){
        for(int j=0;j<submask[i].size();j++){
            cout<<submask[i][j]<<" ";
        }
        cout<<"\n";
    }
}