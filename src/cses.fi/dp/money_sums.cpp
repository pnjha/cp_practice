#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,sum = 0;
	cin>>n;

	vector<int> arr(n);

	for(int i = 0;i<n;i++){
		cin>>arr[i];
		sum += arr[i];
	}

	vector<int> dp(sum+1,0);
	dp[0] = 1;

	for(int i = 0;i<arr.size();i++){
		for(int j = dp.size()-1;j>=arr[i];j--){
			if(dp[j-arr[i]]>0){
				dp[j] = 1;
			}
		}
	}
	
	int size = 0;

	for(int i = 1;i<dp.size();i++){
		if(dp[i]!=0)
			size++;
	}

	cout<<size<<"\n";

	for(int i = 1;i<dp.size();i++){
		if(dp[i]!=0){
			cout<<i<<" ";
		}
	}

	cout<<"\n";

	return 0;
}


// #include<bits/stdc++.h>

// using namespace std;

// struct hash_pair { 
//     template <class T1, class T2> 
//     size_t operator()(const pair<T1, T2>& p) const
//     { 
//         auto hash1 = hash<T1>{}(p.first); 
//         auto hash2 = hash<T2>{}(p.second); 
//         return hash1 ^ hash2; 
//     } 
// }; 

// // set<int> s;
// vector<int> s;
// unordered_map<pair<int,int>,bool,hash_pair> memo;


// void dfs(vector<int>& arr, int index, int sum){

// 	if(memo.find({index,sum})!=memo.end())
// 		return;

// 	if(index >= arr.size())
// 		return;

// 	memo[{index,sum}] = true;

// 	// s.insert(sum);
// 	s.push_back(sum);

// 	for(int i = index+1;i<arr.size();i++){
// 		dfs(arr,i,sum+arr[i]);
// 	}
// }

// int main(){

// 	ios_base::sync_with_stdio(NULL);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	int n;
// 	cin>>n;

// 	s.clear();
// 	memo.clear();

// 	vector<int> arr(n);
// 	unordered_map<int,bool> used;

// 	for(int i = 0;i<n;i++)
// 		cin>>arr[i];

// 	for(int i = 0;i<arr.size();i++){
// 		if(used.find(arr[i]) == used.end()){
// 			used[arr[i]] = true;
// 			// s.insert(arr[i]);
// 			s.push_back(arr[i]);
// 			dfs(arr,i,arr[i]);
// 		}
// 	}

// 	set<int> temp(s.begin(),s.end());
// 	s.clear();
// 	cout<<temp.size()<<"\n";

// 	for(auto itr = temp.begin();itr!=temp.end();itr++)
// 		cout<<*itr<<" ";
// 	cout<<"\n";

// 	return 0;
// }


// // #include<bits/stdc++.h>

// // using namespace std;

// // int main(){

// // 	ios_base::sync_with_stdio(NULL);
// // 	cin.tie(NULL);
// // 	cout.tie(NULL);

// // 	int n,sum = 0;
// // 	cin>>n;

// // 	vector<int> arr(n);
// // 	unordered_map<int,int> look_up;

// // 	for(int i = 0;i<n;i++){
// // 		cin>>arr[i];
// // 		sum += arr[i];
// // 		look_up[arr[i]]++;
// // 	}

// // 	sort(arr.begin(),arr.end());

// // 	vector<vector<unordered_map<int,int>>> dp(sum+1);
// // 	vector<int> temp_vec;
// // 	unordered_map<int,int> temp_table;

// // 	int cnt = 0,k = 0,temp = 0;

// // 	for(int i = 0;i<arr.size();i++){

// // 		for(int j = arr[0];j<sum+1;j++){

// // 			if(arr[i] > j)
// // 				continue;

// // 			if(j - arr[i] == 0){
				
// // 				if(dp[j].size()==0){
// // 					cnt++;
// // 					temp_table[arr[i]] = 1;
// // 					dp[j].push_back({temp_table});
// // 					temp_table.clear();
// // 				}
			
// // 			}else{

// // 				k = j - arr[i];

// // 				for(int l = 0;l<dp[k].size();l++){

// // 					temp = dp[k][l][arr[i]];

// // 					if(temp+1<=look_up[arr[i]]){

// // 						temp_table.clear();
// // 						temp_table = dp[k][l];
// // 						temp_table[arr[i]]++;

// // 						if(dp[j].size()==0)
// // 							cnt++;
						
// // 						dp[j].push_back(temp_table);
						
// // 						temp_table.clear();		
// // 					}

// // 					temp = 0;
// // 				}
// // 			}
// // 		}
// // 	}

// // 	cout<<cnt<<"\n";

// // 	for(int i = arr[0];i<sum+1;i++){
// // 		if(dp[i].size()>0)
// // 			cout<<i<<" ";
// // 	}

// // 	cout<<"\n";

// // 	return 0;
// // }
