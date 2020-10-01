#include<bits/stdc++.h>

using namespace std;

vector<int> lpsCons(string str){

	int i=1,j=0;
	vector<int> lps(str.size(),0);

	lps[0] = 0;

	while(i<str.size()+1){

		if(str[i]==str[j]){
			lps[i] = j+1;
			j++;
			i++;
		}else{
			if(j!=0){
				j = lps[j-1];
			}else if(j==0){
				i++;
			}
		}
	}

	return lps;
}


int main(){

	vector<int> lps;

	string str = "aba";

	lps = lpsCons(str);

	for(int i=0;i<lps.size();i++){
		cout<<lps[i]<<" ";
	}

	cout<<"\n";

}
