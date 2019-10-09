// https://www.codechef.com/problems/ENCD12

#include<bits/stdc++.h>

using namespace std;

string get_swaps(string str){

	// if(str.length()==1)
	// 	return "0";

	if(str.length()==2){
		if(str[0]==str[1]) return "0";
		else return "Impossible";
	}	

	int cnt = 0, n = str.length();

	int i = 0,j = n-1,k;

	while(i<j){

		if(str[i]==str[j]){
			i++;
			j--;
		}else{

			k = j-1;

			for(;k>=i;k--){
				if(str[i]==str[k])
					break;
			}

			if(k == i) return "Impossible";

			for(int l = k;l<j;l++){

				swap(str[l],str[l+1]);
				cnt++;
			}

			// cout<<str<<"\n";
		}	
	}

	return to_string(cnt);
}

int main(){

	string str;

	while(cin>>str){

		if(str=="0")
			return 0;

		cout<<get_swaps(str)<<"\n";
	}

	return 0;
}
