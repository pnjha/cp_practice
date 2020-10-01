#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	int cnt=0,temp=n,power=0,ans=0,i=0;

	vector<int> bits(64,0);

	while(temp){
		power += 1;
		if(temp/10>=1)
			ans += int(pow(2,power));
		if(temp%10==4)
			bits[i] = 0;
		else
			bits[i] = 1;
		i++;
		temp /= 10;
	}

	temp = 0;

	for(int i = bits.size()-1;i>=0;i--){

		temp <<= 1;
		if(bits[i] == 1)
			temp |= 1;
	}

	// cout<<temp<<"\n";
	ans += temp + 1; 
	cout<<ans<<"\n";

	return 0;
}
