#include<bits/stdc++.h>
#define N 16
using namespace std;

int cnt = 0;

bitset<N> col_check;
bitset<2*N> left_diag; //(i+j)
bitset<2*N> right_diag; //(n+(i-j))

void dfs(int n, int row){

	if(n == row){
		cnt++;
		return;
	}

	for(int j = 0;j<n;j++){

		if(col_check[j] == 0 && left_diag[row + j] == 0 && right_diag[n+row-j] == 0){

			col_check[j] = 1;
			left_diag[row + j] = 1;
			right_diag[n+row-j] = 1;

			dfs(n,row+1);

			col_check[j] = 0;
			left_diag[row+j] = 0;
			right_diag[n+row-j] = 0;
		}

	}	

}

int main(){

	int n;
	cin>>n;

	cnt = 0;

	for(int j = 0;j<n;j++){

		col_check[j] = 1;
		left_diag[j] = 1;
		right_diag[n-j] = 1;

		dfs(n,1);

		col_check[j] = 0;
		left_diag[j] = 0;
		right_diag[n-j] = 0;

	}
	

	cout<<cnt<<"\n";

	return 0;
}