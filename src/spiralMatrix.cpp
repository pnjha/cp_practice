#include<bits/stdc++.h>

using namespace std;

int main(){

	int rows,cols;
	cin>>rows>>cols;

	int arr[rows][cols];

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[i][j];
		}
	}

	int ub=0,db=rows,rb=cols,lb=0,counter=0;

	while(ub<db&&lb<rb){
		// cout<<"counter: "<<counter<<"\n";
		for(int i=lb;i<rb;i++){
			cout<<arr[ub][i]<<"\n";
			counter++;
			// cout<<"one\n";
		}

		ub += 1;

		// cout<<"\n"<<ub<<" "<<db<<" "<<rb<<" "<<lb<<"\n";

		for(int i=ub;i<db;i++){
			cout<<arr[i][rb-1]<<"\n";
			counter++;
			// cout<<"two\n";
		}

		rb -= 1;

		// cout<<"\n"<<ub<<" "<<db<<" "<<rb<<" "<<lb<<"\n";

		if(ub<db){

			for(int i=rb-1;i>=lb;i--){
				cout<<arr[db-1][i]<<"\n";
				counter++;
				// cout<<"three\n";
			}

			db -= 1;

		}
		

		// cout<<"\n"<<ub<<" "<<db<<" "<<rb<<" "<<lb<<"\n";

		if(lb<rb){
			for(int i=db-1;i>=ub;i--){
				cout<<arr[i][lb]<<"\n";
				counter++;
				// cout<<"four\n";
			}

			lb += 1;			
		}


		// cout<<"\n"<<ub<<" "<<db<<" "<<rb<<" "<<lb<<"\n";

	}

	return 0;
}