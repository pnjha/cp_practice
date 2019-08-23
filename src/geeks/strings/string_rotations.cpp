#include<bits/stdc++.h>

using namespace std;

int find_rotaion_point(string& a, string& b){

	int n = a.length();
	int m = b.length();

	if(n!=m){
		return -1;
	}

	int i = 1, l = 0;

	vector<int> lps(n,0);

	while(i<n){

		if(a[i] == b[l]){

			lps[i] = ++l;
			i++;

		}else{

			if(l == 0){

				i++;

			}else{

				l = lps[l-1];
			}
		}
	}

	i = 0;

	for(int k = lps.back();k<m;k++){
		if(b[k] != a[i]){
			cout<<"1here\n";
			return -1;
		}
		i++;
	}

	return lps.back();
}

int main(){

	string a = "ABACD";
	string b = "CDABA";

	cout<<"Rotation point is: "<<find_rotaion_point(a,b)<<"\n";

}
