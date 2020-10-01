#include<bits/stdc++.h>

using namespace std;

int main(){

	int a1,a2,a3;
	string s1 = "ab",s2 = "fgefeg",s3 = "gh";

	cin>>a1>>a2>>a3;
	cin>>s1>>s2>>s3;

	char cvec[s2.size()+1];

	int j = 0,index;

	for(int i = 0;i<s2.size();i++){
		if(s2[i]<=s3[0]){
			cvec[j] = s2[i];
			j++;
		}
	}

	cvec[j] = '\0';
	s2 = string(cvec);


	vector<pair<char,int>> vec;

	for(int i = 0;i<s2.length();i++){
		vec.push_back({s2[i],i});
	}

	sort(vec.begin(),vec.end());

	memset(cvec,0,sizeof cvec);

	j = 0;
	for(int i = 0;i<vec.size();i++){
		if(i == 0){
			cvec[j] = vec[i].first;
			index = vec[i].second;
			j++;
		}else{
			// cout<<vec[i].first<<" "<<vec[i].second<<"\n";
			if(vec[i].second>index){
				index = vec[i].second;
				cvec[j] = vec[i].first;
				j++;
			}
		}
	}
		
	cvec[j] = '\0';
	s2 = string(cvec);

	memset(cvec,0,sizeof cvec);

	j = 0;
	for(int i = 0,k = 0;i<s2.length() && k<s3.length();){
		if(s2[i]==s3[k]){
			k++;
		}else if(s2[i]<s3[k]){
			cvec[j] = s2[i];
			j++;
			i++;
		}else{
			i++;
		}
	}

	cvec[j] = '\0';
	s2 = string(cvec);

	cout<<(s1+s2+s3)<<"\n";

	return 0;
}
