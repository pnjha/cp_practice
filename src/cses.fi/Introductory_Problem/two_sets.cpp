#include<bits/stdc++.h>

using namespace std;

// bool dfs(vector<bool>& set1,int index,int sum){

// 	if(sum == 0){
// 		return true;
// 	}

// 	for(int i = index+1;i<set1.size();i++){
			
// 		set1[i] = true;
// 		if(dfs(set1,i,sum-i))
// 			return true;
// 		set1[i] = false;
// 	}	

// 	return false;
// }

void gaussian_method(int n){
	vector<int> s1,s2;

	s1.push_back(1);
	s1.push_back(2);

	s2.push_back(3);

	int left = 4,right = n;
	bool flag = true;
	
	while(left<right){
		// cout<<left<<" "<<right<<"\n";
		if(right<0)
			break;
		if(flag){
			s1.push_back(left);
			s1.push_back(right);
			flag = false;
		}else{
			s2.push_back(left);
			s2.push_back(right);
			flag = true;
		}
		left++;
		right--;
	}

	cout<<s1.size()<<"\n";

	for(int i = 0;i<s1.size();i++)
		cout<<s1[i]<<" ";

	cout<<"\n";
	cout<<s2.size()<<"\n";

	for(int i = 0;i<s2.size();i++)
		cout<<s2[i]<<" ";
	cout<<"\n";
}

int main(){

	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;

	long long int sum = ((n)*(n+1))/2;

	if(sum&1){

		cout<<"NO\n";

	}else{

		cout<<"YES\n";

		if(n!=4)
			gaussian_method(n);
		else{

			cout<<"2\n";
			cout<<"1 4\n2\n2 3\n";
		}

	// 	bool flag = false;
	// 	vector<bool> set1(n+1,false);
		
	// 	sum = sum/2;

	// 	// for(int i = 1;i<=n;i++){
	// 	// 	cout<<i<<"\n";
	// 	// 	set1[i] = true;
	// 	// 	if(dfs(set1,1,sum-1))
	// 	// 		break;
	// 	// 	set1[i] = false;
	// 	// }

	// 	int sum_odd = 0, sum_even = 0; 

	// 	for(int i = 1;i<=n;i++){
	// 		if(i%2==0){
	// 			sum_even += i;
	// 			set1[i] = true;
	// 		}else{
	// 			sum_odd += i;
	// 		}
	// 	}

	// 	int diff = 0;

	// 	if(sum_odd!=sum_even){
	// 		diff = abs(sum_even - sum_odd)/2;
	// 		if(sum_even>sum_odd){

	// 			if(set1[diff] == true){
	// 				set1[diff] = false;
				
	// 			}else{
	// 				set1[diff+1] = false;
	// 				set1[diff] = true;
	// 			}
	// 		}
	// 		else{
	// 			if(set1[diff] == false){
	// 				set1[diff] = true;
	// 			}else{
	// 				set1[diff] = false;
	// 				set1[diff+1] = true;
	// 			}
	// 		}
	// 	}

	// 	int count = 0;

	// 	for(int i = 1;i<set1.size();i++){
	// 		if(set1[i])
	// 			count++;
	// 	}

	// 	cout<<count<<"\n";

	// 	for(int i = 1;i<set1.size();i++){
	// 		if(set1[i])
	// 			cout<<i<<" ";
	// 	}

	// 	cout<<"\n"<<n-count<<"\n";

	// 	for(int i = 1;i<set1.size();i++){
	// 		if(!set1[i])
	// 			cout<<i<<" ";
	// 	}
	// 	cout<<"\n";
	}

	return 0;
}
