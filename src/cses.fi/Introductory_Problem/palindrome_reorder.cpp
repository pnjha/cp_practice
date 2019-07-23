#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);

	string str;
	cin>>str;

	vector<pair<int,char>> char_count(26);

	for(int i = 0;i<str.length();i++){
		char_count[str[i]-'A'] = {char_count[str[i]-'A'].first+1,str[i]};
	}

	sort(char_count.begin(),char_count.end());


	bool even = false,first = true;

	if(str.length()%2==0)
		even = true;

	string ans = "";
	int len = 0;

	for(int i = 0;i<char_count.size();i++){

		if(char_count[i].first == 0)
			continue;

		if(char_count[i].first == 1&&first){

			first = false;

			if(even){
			
				cout<<"NO SOLUTION\n";
				return 0;
			}
		}else{

			if(char_count[i].first%2==1&&!first){

				cout<<"NO SOLUTION\n";
				return 0;	
			}else if(char_count[i].first%2==1&&first){
				first = false;	
			}
		}
	}

	sort(char_count.begin(),char_count.end(),[&](pair<int,char> p1, pair<int,char>p2){
		if(p1.first>p2.first)
			return true;
		return false;
	});
	
	// cout<<char_count[i].second<<" "<<char_count[i].first<<" \n";

	int index = -1;

	for(int i = 0;i<char_count.size();i++){
	
		len = char_count[i].first;

		if(len == 0){
			continue;
		
		}else if(len%2==1){
			index = i;
			continue;
		}else if(len == 1){
			cout<<char_count[i].second;
			char_count[i].first = 0;
		}

		while(char_count[i].first>len/2){
			cout<<char_count[i].second;
			char_count[i].first--; 
		}
	}

	if(index!=-1)	
		while(char_count[index].first){
			cout<<char_count[index].second;
			char_count[index].first--; 
		}

	sort(char_count.begin(),char_count.end());

	for(int i = 0;i<char_count.size();i++){
		
		// cout<<char_count[i].second<<" "<<char_count[i].first<<" \n";

		len = char_count[i].first;

		if(len == 0){
			continue;
	
		}else if(len == 1){
			cout<<char_count[i].second;
			char_count[i].first = 0;
		}else{

			while(char_count[i].first){
				cout<<char_count[i].second;
				char_count[i].first--; 
			}
		}
	}


	cout<<"\n";
	return 0;
}