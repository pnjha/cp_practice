//binary representation from any base(+ve)

#include<bits/stdc++.h>

using namespace std;

string baseX(int n, int base){
        
    if(n==0||base==0)
        return "0";
    
    string ans = "";
    
    while(n!=0){    
        ans = to_string(n%base) + ans;
        n = n/base;
    }
    
    return ans==""?"0":ans;
}

int main(){

	int n,b;
	cin>>n>>b;

	cout<<baseX(n,b)<<"\n";

	return 0;
}
