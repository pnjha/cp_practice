#include<bits/stdc++.h>

using namespace std;


int maxChunksToSorted_stack_approach(vector<int>& arr) {
        
	queue<int> q;
	vector<bool> visited(arr.size(),false);
	
	int search_element = 0,cnt = 0;

	for(int i = 0;i<arr.size();i++){

		visited[arr[i]] = true;
		
		if(arr[i]==search_element){

			if(q.empty()){
				cnt++;
				if(i+1<arr.size() && arr[i+1] == i+1)
					search_element = i+1;
				else if(i+1<arr.size())
					search_element = arr[i+1] - 1;
				continue;
			}else{

				if(search_element!=0 && visited[search_element-1]==false){
					search_element--;
				}
				else if(visited[q.front()-1]){
					search_element = q.front();
					q.pop();
				}
				else
					search_element = q.front()-1;
			}
		
		}else{

			if(visited[arr[i]-1]==false && search_element!=(arr[i]-1)){

				q.push(arr[i]-1);

			}

		}

		while(!q.empty() && visited[q.front()]){
            q.pop();
        }
	}

	if(cnt == 0)
		cnt++;

	return cnt;
}

int maxChunksToSorted_set_approach(vector<int>&arr){

	int se = 0,cnt=0;

	vector<pair<int,int>> a(arr.size());

	for(int i = 0;i<arr.size();i++){
		a[i].first = arr[i];
		a[i].second = i;
	}

	sort(a.begin(),a.end());
	set<int> backlog;

	for(int i = 0;i<a.size();i++){

		if(a[i].second == se){

			if(backlog.size() == 0){

				cnt++;
				se = se + 1;
			
			}else{

				if(backlog.find(se+1)==backlog.end()){

					se = se + 1;					

				}else{

					se = se + 1;

					while(backlog.size()>0 && backlog.find(se)!=backlog.end()){

						backlog.erase(se);
						se = se + 1;
					}

					if(backlog.size() == 0){

						cnt++;

					}

				}

			}

		}else{

			backlog.insert(a[i].second);

		}

	}

	return cnt;
} 

int main(){
	
	vector<int> arr = {0,4,7,5,3,6,9,2,1,8};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {1,4,0,2,3,5};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {5,0,1,2,4,3,6};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {3,2,1,0,4};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {1,0,2,3,4};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {4,3,2,1,0};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {2,0,1,3};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {0,2,1};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {0,1,3,2,4};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	arr = {0,4,2,3,1};
	cout<<maxChunksToSorted_stack_approach(arr)<<"\n";
	cout<<maxChunksToSorted_set_approach(arr)<<"\n";

	return 0;
}