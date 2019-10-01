// #include<bits/stdc++.h>

// using namespace std;

// struct comparator{
	
// 	bool operator ()(pair<int,int> a, pair<int,int> b){
// 		if(a.second<b.second){
// 			return false;
// 		}		
// 		else if(a.second == b.second){
// 			if(a.first<b.first){
// 				return false;
// 			}
// 		}
// 		return true;
// 	}
// };


// int main(){

// 	int n,t;
// 	cin>>n>>t;

// 	vector<int> arr(n);
// 	priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> pq;

// 	for(int i = 0;i<arr.size();i++){
// 		cin>>arr[i];
// 		pq.push({arr[i],arr[i]});
// 	}

// 	int max_time = INT_MIN;
// 	pair<int,int> temp;

// 	for(int i = 0;i<t;i++){

// 		temp = pq.top();
// 		pq.pop();

// 		if(max_time<temp.second)
// 			max_time = temp.second;

// 		temp.second += temp.first;
// 		pq.push(temp);
// 	}


// 	cout<<max_time<<"\n";

// 	return 0;
// }

#include<bits/stdc++.h>

using namespace std;

//using bisection method
unsigned long long int get_tasks(vector<unsigned long long int>&arr,unsigned long long int time){
	unsigned long long int sum = 0;
	for(unsigned long long int i = 0;i<arr.size();i++)
		sum += time/arr[i];
	return sum;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unsigned long long int n,t,max_ele = INT_MIN;
	cin>>n>>t;

	vector<unsigned long long int> arr(n);
	
	for(unsigned long long int i = 0;i<arr.size();i++){
		cin>>arr[i];
		if(max_ele<arr[i])
			max_ele = arr[i];
	}

	if(n==1){
		cout<<(unsigned long long int)(t*arr[0])<<"\n";
		return 0;
	}

	unsigned long long int max_time = max_ele * t;

	unsigned long long int left = 1,right = max_time,mid = -1,tasks = 0;

	while(left<right){

		mid = (left + right)/2;

		tasks = get_tasks(arr,mid);

		// cout<<left<<" "<<right<<" "<<mid<<" "<<tasks<<"\n";

		if(tasks<t)
			left = mid+1;
		else
			right = mid;
	}

	cout<<right<<" \n";

	return 0;
}