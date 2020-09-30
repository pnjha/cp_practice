//permutation of abc will be abc, acb, bab, bca, cba, cab...........but pemutation of aab is 
//aab, aba, aab, aba, baa, baa.............some are repeating.....to avoid this we use set.....
//Give input as aab and check the result........
#include<iostream>
#include<set>
#include<string>
using namespace std;
void permute(char a[], int i,set<string> &s){
	if(a[i]=='\0'){
	//	cout<<a<<endl;
		string t(a);
		s.insert(t);
		return;
	}
	//recursive case
	for(int j=i; a[j]!='\0'; j++){
		swap(a[i],a[j]);
		permute(a,i+1,s);
		swap(a[i],a[j]);
	}
}

int main(){

	cout<<"Enter the string whose permutation you want ";

	char a[100];
	cin>>a;
	set<string> s;
	permute(a,0,s);

	//loop over the string
	for(auto str:s){
		cout<<str<<endl;
	}

	return 0;
}