#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	vector<int> arr(n);
	vector<bool> v(n,false);

	for(int i = 0;i<n;i++)
		cin>>arr[i];

	bool flag = true;

	for(int i=n-2; i>=0; i--){
        if(arr[i+1] < arr[i]){
            if(arr[i+1]+1 == arr[i])
                arr[i]--;
            else{
                flag = false;
                break;
            }
        }
    }

	if(flag)
		cout<<"Yes\n";
	else
		cout<<"No\n";

	return 0;
}
