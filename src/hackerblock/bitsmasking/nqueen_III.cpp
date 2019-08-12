//Find number of solutions for nXn chess board
//time per row is O(k) where k is number of valid position of queen for a row

#include<bits/stdc++.h>

using namespace std;

int cnt = 0;

void solve(int row_mask, int left_dia, int right_dia, int end_mask){

	if(row_mask == end_mask){
		cnt++;
		return;
	}

	int safe = end_mask & (~(row_mask|left_dia|right_dia));
	int p;

	while(safe){
		p = safe & (-safe);
		safe -= p;
		solve(row_mask|p, (left_dia|p)<<1, (right_dia|p)>>1, end_mask);
	}
}

int main(){

	int n;
	cin>>n;

	cnt = 0;

	int end_mask = (1<<n)-1;

	solve(0,0,0,end_mask);

	cout<<cnt<<"\n";

	return 0;
}