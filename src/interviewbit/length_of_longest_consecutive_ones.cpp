#include<bits/stdc++.h>

using namespace std;

int solve(string A) {
    
    vector<int> arr;
    int cnt = -1,prev = -1,ans = 0,count_ones = 0;
    
    for(int i = 0;i<A.length();i++){
        
        if(A[i]=='0'){
            if(cnt!=-1)
                arr.push_back(cnt);
            cnt=-1;
            arr.push_back(0);
        }else{
        	count_ones++;
            if(cnt==-1)
                cnt=1;
            else
                cnt++;
        }
    }
    
    if(cnt!=-1)
        arr.push_back(cnt);

    int max_val = INT_MIN, max_index = -1,temp = 0;

    for(int i = 0;i<arr.size();i++){

    	if(arr[i] == 0){

    		if(i-1>=0&&arr[i-1]!=0)
    			temp += arr[i-1];
    		if(i+1<arr.size()&&arr[i+1]!=0)
    			temp += arr[i+1];
    		if(temp>max_val){
    			max_val = temp;
    		}
    	}
    	temp = 0;
    }

    if(count_ones>max_val)
    	ans = max_val+1;
    else
    	ans = max_val;

    return ans;
}


int main(){

	string s = "100011111111111";

	cout<<solve(s)<<"\n";

	return 0;
}