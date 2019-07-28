#include<bits/stdc++.h>

using namespace std;

//implementation of upper bound
int CeilIndex(std::vector<int>& v, int l, int r, int key) { 
    while(r - l > 1){ 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
}

int lis(const vector<int> &v) {
    
    if (v.size() == 0) 
        return 0; 

    vector<int> tail(v.size(), 0); 
    int length = 1;

    tail[0] = v[0]; 
    for(size_t i = 1; i < v.size(); i++) { 

        if(v[i] < tail[0]) 
            tail[0] = v[i]; 

        else if(v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 

        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
    } 

    return length;
    
}


int lis(vector<int> a){

	vector<int> arr(a.size(),1);
	int counter = 0;

	for(int i = 1;i<a.size();i++){
		for(int j = 0;j<i;j++){
			if(a[j]<a[i] && arr[i]<arr[j]+1){
				arr[i] = arr[j] + 1;
			}
		}
	}
	
	int max = INT_MIN;

	for(int i = 0;i<arr.size();i++){
		cout<<arr[i]<<" ";
		if(arr[i]>max)
			max = arr[i];
	}
	cout<<"\n";
	return max;
}

int main(){
	
	vector<int> arr;
	
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(-1);
	arr.push_back(0);
	arr.push_back(6);
	arr.push_back(2);
	arr.push_back(3);

	cout<<lis(arr)<<"\n";

	return 0;
}
