#include<bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,temp,index=-1;
	cin>>n;

	vector<int> ans;

	for(int i = 0;i<n;i++){

		cin>>temp;
		if(ans.size()==0){
			ans.push_back(temp);
		}else{

			index = (upper_bound(ans.begin(),ans.end(), temp) - ans.begin());

			// cout<<"here: "<<index<<" "<<temp<<"\n";

			if(index == ans.size()){
				ans.push_back(temp);
			}else if(index>=0){
				// index -= 1;
				if(ans[index] > temp)
					ans[index] = temp;
				else if(index+1==ans.size())
					ans.push_back(temp);
				else{
					ans[index+1] = temp;
				}
			}
		}

		// for(int i = 0;i<ans.size();i++)
		// 	cout<<ans[i]<<" ";
		// cout<<"\n";
	}

	cout<<ans.size()<<"\n";

	return 0;
}