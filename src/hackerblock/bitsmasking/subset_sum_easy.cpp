// // https://hack.codingblocks.com/practice/p/366/136

// Mike is a very passionate about sets. Lately, he is busy solving one of the problems on sets. He has to find whether if the sum of any of the non-empty subsets of the set A is zero.
// Input Format:

// The first line contains an integer T, which is the total number of test cases. T

// test cases follow.

// Each test case consists of two lines.

// The first line consists of a single integer N, which is the number of elements

// present in the set A.

// The second line contains the integer in the set.
// Constraints:

// 1 ≤ T ≤10
// 1 ≤ N ≤ 4
// -10^5 ≤ A[i] ≤ 10^5

// Output Format:

// If the sum of any of the subset is zero, then print “Yes” (without

// quotes) else print “No”(without quotes).
// Sample Input:

// 1
// 4
// 1 2 3 -3

// Sample Output:

// Yes

// Explanation:

// The sum of the subset {3,-3} is zero.

#include<bits/stdc++.h>
#define SIZE 2000000
using namespace std;

string subset_sum(vector<int>& arr,int min_val,int max_val){

	// if(min_val > 0 || max_val < 0)
	// 	return "No";

	// if(min_val == 0 || max_val == 0)
	// 	return "Yes";

	int size = max_val+min_val+1;

	bitset<SIZE> b;

	for(int i = 0;i<arr.size();i++){

		for(int j = max_val;j>=min_val;j--){

			if(((j-arr[i])+abs(min_val) >= 0 && b[(j-arr[i])+abs(min_val)] == 1) || j == arr[i]){

				b[j+abs(min_val)] = 1;
			}

		}

		for(int i = min_val;i<=max_val;i++)
			cout<<b[i+abs(min_val)]<<" ";
		cout<<"\n";
		if(b[abs(min_val)]==1)
			return "Yes";

	}

	return "No";
}

int main(){

	int t,n,min_val = INT_MAX,max_val = INT_MIN;
	cin>>t;

	vector<int> arr;

	while(t--){

		cin>>n;

		arr.clear();
		arr.resize(n,0);
		min_val = 0;
		max_val = 0;

		for(int i = 0;i<n;i++){
			cin>>arr[i];
			if(arr[i] > 0)
				max_val += arr[i];
			else if(arr[i] < 0)
				min_val += arr[i];
		}

		cout<<subset_sum(arr,min_val,max_val)<<"\n";

	}

	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

// 	int t,n,prefix_sum=0,temp;
// 	cin>>t;

// 	bool flag = false;
// 	unordered_map<int , bool> present;

// 	while(t--){

// 		cin>>n;

// 		prefix_sum = 0;
// 		flag = false;
// 		present.clear();

// 		for(int i = 0;i<n;i++){
			
// 			cin>>temp;
			
// 			if(temp == 0){
// 				// cout<<"f\n";
// 				flag = true;

// 			}else if(!flag){

// 				if(i == 0){
// 					prefix_sum = temp;
// 					present[prefix_sum] = true;
// 				}
// 				else{
// 					prefix_sum += temp;
// 					if(prefix_sum == 0 || present.count(prefix_sum)!=0){
// 						// cout<<"g\n";
// 						flag = true;
// 					}
// 					present[prefix_sum] = true;
// 				}
// 			}
// 			cout<<prefix_sum<<"\n";
// 		}

// 		if(prefix_sum == 0){
// 			flag = true;
// 		}
			
// 		if(flag)
// 			cout<<"Yes\n";
// 		else
// 			cout<<"No\n";
// 	}

// 	return 0;
// }