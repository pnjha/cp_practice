#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--){
	    
	    string str1,str2,temp1 = "",temp2 = "";
	    cin>>str1;
	    cin>>str2;
	    
	    unordered_map<char,vector<int>> hash;
	    vector<int> temp;
	    
	    
	    for(int i = 0;i<str2.length();i++){
	        temp.clear();
	        if(hash.find(str2[i])==hash.end()){
	            temp.push_back(i);
	            hash[str2[i]] = temp;
	        }else{
	            temp = hash[str2[i]];
	            temp.push_back(i);
	            hash[str2[i]] = temp;
	        }
	    }
	    
	    vector<int> index;

	    for(int i=0;i<str1.length();i++){
	        temp.clear();
	        if(hash.find(str1[i])==hash.end()){
	            temp1 += str1[i];
	        }else{
	            
	            temp = hash[str1[i]];
	            for(int j = 0;j<temp.size();j++){
	                index.push_back(temp[j]);
	            }
	            temp.clear();
	            hash[str1[i]] = temp;
	        }
	    }
	    
	    sort(index.begin(),index.end());

	    for(int i = 0;i<index.size();i++)
	    	cout<<index[i]<<" ";
	    cout<<"\n";

	    for(int i = 0,j = 0;i<str2.length();i++){
	    	if(str2[i]!=str2[index[j]])
	    		temp2 += str2[i];
	    	else{
	    		j++;
	    	}
	    }
	    
	    temp1 = temp1+temp2;
	    cout<<temp1<<"\n";
	}
	
	return 0;
}