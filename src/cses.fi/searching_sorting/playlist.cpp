#include<bits/stdc++.h>
#define int long long int
using namespace std;
 
int32_t main(){
 
	int n,start = -1,end = -1,max_len = LONG_MIN;
	cin>>n;
 
	vector<int> arr(n,0);
	map<int,bool> present;
 
	for(int i = 0;i<n;i++){
		
		end = i;
 
		cin>>arr[i];
 
		if(i == 0){
		
			start = 0;
			present[arr[i]] = true;
 
		}else{
 
			if(present[arr[i]]){
 
				if(end - start > max_len)
					max_len = end - start;
 
				while(present[arr[i]] && start<end){
 
					present[arr[start]] = false;
					start++;
 
				}
 
				present[arr[i]] = true;				
 
			}else{
 
				present[arr[i]] = true;				
 
			}
 
		}	
 
	}
 
	if((end - start + 1)>max_len){
		max_len = (end - start + 1);
	}
 
	cout<<max_len<<"\n";
 
	return 0;
}

