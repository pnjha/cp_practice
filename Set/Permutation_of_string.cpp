//permutation of abc will be abc, acb, bab, bca, cba, cab...........but pemutation of aab is 
//aab, aba, aab, aba, baa, baa.............some are repeating.....to avoid this we use set.....
#include<iostream>
#include<string>
using namespace std;
void permute(char a[], int i){
	if(a[i]=='\0'){
		cout<<a<<endl;
		return;
	}
	//recursive case
	for(int j=i; a[j]!='\0'; j++){
		swap(a[i],a[j]);
		permute(a,i+1);
		swap(a[i],a[j]);
	}
}

int main(){

	cout<<"Enter the string whose permutation you want ";

	char a[100];
	cin>>a;
	permute(a,0);
		
	return 0;
}