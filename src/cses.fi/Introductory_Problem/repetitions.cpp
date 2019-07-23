#include<bits/stdc++.h>

using namespace std;

int main(){


	string str;

	cin>>str;

	int len = 0, max_len = INT_MIN;
	int i = 0,j = 0;

	for(;j<str.length();){

		if(i == j){

			len = 1;
			j++;

		}else{

			if(str[i] == str[j]){
				j++;
				len++;
			}else{

				if(len>max_len)
					max_len = len;
				len = 0;
				i = j;				
			}
		}
	}


	if(len>max_len)
		max_len = len;

	cout<<max_len<<"\n";

	return 0;
}
