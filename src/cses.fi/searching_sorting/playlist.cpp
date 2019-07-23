#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,start = -1,end = -1,max_len = INT_MIN,min_ele = INT_MAX,max_ele = INT_MIN;
	cin>>n;

	vector<int> arr(n+1,0);
	// unordered_map<int,bool> present;

	for(int i = 1;i<n+1;i++){

		cin>>arr[i];
	}

	for(int i = 1;i<n+1;i++){

		if(arr[i]>max_ele){
			max_ele = arr[i];
		}
		else if(arr[i]<min_ele){
			min_ele = arr[i];
		}
	}

	cout<<max_ele<<" "<<min_ele<<"\n";

	int s = (max_ele - min_ele+10);

	vector<int> present(s,-1);


	for(int i = 1;i<n+1;i++){
		
		end = i;

		if(i == 1){
		
			start = i;
			present[arr[i]-min_ele] = i;

		}else{

			if(present[arr[i]-min_ele]!=-1){

				if(end - start > max_len)
					max_len = end - start;
				
				if(present[arr[i]-min_ele]>=start){

					start = present[arr[i]-min_ele]+1;
					present[arr[i]-min_ele] = i;
					
				}else{

					present[arr[i]-min_ele] = i;

				}			

			}else{

				present[arr[i]-min_ele] = i;				

			}

		}
		// for(int i = 0;i<11;i++)
		// 	cout<<i<<" ";
		// cout<<"\n";

		// for(int i = 0;i<11;i++)
		// 	cout<<present[i]<<" ";
		// cout<<"\n";


		cout<<"start,end: "<<start<<" "<<end<<"\n";
	}	
	cout<<"start,end: "<<start<<" "<<end<<"\n";

	if((end - start + 1)>max_len){
		max_len = (end - start + 1);
	}

	cout<<max_len<<"\n";

	return 0;
}
