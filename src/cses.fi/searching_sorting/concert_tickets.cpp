#include<bits/stdc++.h>

using namespace std;

unordered_map<int,bool> used;

int bsearch(vector<int>& price, int val){

	// cout<<"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP\n";

	int left = 0, right = price.size()-1, mid = 0;
	int index = -1;

	while(left<=right){

		// cout<<"left: "<<left<<" right: "<<right<<"\n";
		
		mid = (left+right)/2;

		if(price[mid] <= val){

			if(mid+1<price.size()&&price[mid+1] == price[mid] && used.find(mid+1) == used.end()){	
				left = mid+1;
				// cout<<"one\n";
				continue;
				
			}else if(used.find(mid) == used.end()){
				index = mid;
				// cout<<"two\n";
				break;

			}else if(mid-1>=0&&price[mid-1] == price[mid] && used.find(mid-1) == used.end()){
				right = mid-1;
				// cout<<"three\n";
				continue;
			}else{
				left = 0;
				right = mid -1;
				// cout<<"four\n";
				continue;
				// while(mid>=0){
				// 	if(used.find(mid) == used.end()){
				// 		index = mid;
				// 	}
				// 	mid--;
				// }
				// break;
			}

			break;

		// }else if(price[mid]<val){

		// 	if(used.find(mid)==used.end()){

		// 		index = mid;

		// 	}

		// 	left = mid+1;

		}else{

			right = mid-1;

		}
	}

	if(index!=-1){
		// cout<<"index: "<<index<<"\n";
		used[index] = true;
	}

	return index;
}

int main(){

	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,temp,ans = -1,index = -1;
	cin>>n>>m;

	vector<int> price(n,0);
	
	for(int i = 0;i<n;i++)
		cin>>price[i];

	sort(price.begin(),price.end());

	for(int i = 0;i<m;i++){

		cin>>temp;

		n--;
		if(n>=0){
			index = bsearch(price,temp);
		}
		else{
			// cout<<"here: -1\n";
			continue;
		}
		if(index!=-1)
			cout<<price[index]<<"\n";
		else
			cout<<"-1\n";

		index = -1;
	}


	return 0;
}
