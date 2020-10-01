#include<bits/stdc++.h>

using namespace std;

bool modified_euclidean_distance(vector<int>& a,vector<int>& b){

	double dist = 0.0;

	for(int i = 0;i<a.size();i++){
		dist += pow((a[i] - b[i]),2);
	}

	dist = sqrt(dist);
	
	// cout<<dist<<"\n";
	// cout<<ceil(dist - int(dist))<<"\n";

	if(ceil(dist - int(dist)))
		return false;
	return true;
}

int main(){

	int n,d,count = 0;
	cin>>n>>d;

	vector<vector<int>> points(n,vector<int>(d,0));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<d;j++){
			cin>>points[i][j];
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(modified_euclidean_distance(points[i],points[j]))
				count++;
		}	
	}

	cout<<count<<"\n";

	return 0;
}
