#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {

	vector<vector<int>> row_sum(A.size(),vector<int>(A[0].size(),0));    
    vector<vector<int>> col_sum(A.size(),vector<int>(A[0].size(),0));
    vector<vector<int>> cum_sum(A.size(),vector<int>(A[0].size(),0));

	vector<int> ans;

	for(int i = 0;i<row_sum.size();i++){
		for(int j=0;j<row_sum[i].size();j++){

			if(j==0)
				row_sum[i][j] = A[i][j];
			else
				row_sum[i][j] = A[i][j] + row_sum[i][j-1];
			// cout<<row_sum[i][j]<<" ";
		}
		// cout<<"\n";
	}

	// cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

	for(int i = 0;i<col_sum.size();i++){
		for(int j=0;j<col_sum[i].size();j++){
			
			if(i==0)
				col_sum[i][j] = A[i][j];
			else
				col_sum[i][j] = A[i][j] + col_sum[i-1][j];
			// cout<<col_sum[i][j]<<" ";
		}
		// cout<<"\n";
	}


	// cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

	for(int i = 0;i<cum_sum.size();i++){
		for(int j = 0;j<cum_sum[i].size();j++){
			if(i == 0 && j == 0){
				cum_sum[i][j] = A[i][j];
			}else if(i == 0){
				cum_sum[i][j] = row_sum[i][j];
			}else if(j == 0){
				cum_sum[i][j] = col_sum[i][j];
			}else{
				cum_sum[i][j] = cum_sum[i][j-1] + col_sum[i-1][j] + A[i][j];
			}
			// cout<<cum_sum[i][j]<<" ";
		}
		// cout<<"\n";
	}

	int a=0,b=0,c=0,d=0;

	for(int i = 0;i<B.size();i++){
		
		a=0,b=0,c=0,d=0;
		
		a = cum_sum[D[i]-1][E[i]-1];
		
		if(C[i]-2>=0)
			b = cum_sum[D[i]-1][C[i]-2];
		
		if(B[i]-2>=0)
			c = cum_sum[B[i]-2][E[i]-1];
		
		if(B[i]-2>=0 && C[i]-2>=0)	
			d = cum_sum[B[i]-2][C[i]-2];
		
		ans.push_back((a -b - c + d));
		
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"; 
	}

	return ans;
}

int main(){

	vector<vector<int> > A = {{5, 17, 100, 11},{0,0,2,8}};
	vector<int> B = {1,1};
	vector<int> C = {1,4};
	vector<int> D = {2,2};
	vector<int> E = {2,4};

	// vector<vector<int> > A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
	// vector<int> B = {1,2};
	// vector<int> C = {1,2};
	// vector<int> D = {2,3};
	// vector<int> E = {2,3};

	vector<int> ans = solve(A,B,C,D,E);	

	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";

	return 0;
}
