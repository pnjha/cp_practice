#include <iostream>

using namespace std;
//PAIRSUM2 - CodeChef
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, Q;
	    cin>>n>>Q;
	    int B[n-1];
	    for(int i=0; i<n-1; i++){
	        cin>>B[i];
	    }
	    int p,q,sum;
	    while(Q--){
	        cin>>p>>q;
	        if((p+q)%2 == 0){
	            cout<<"UNKNOWN"<<endl;
	            continue;
	        }
	        if(p>q){
	            swap(p,q);
	        }
	        sum = B[p]+B[q-1];
	        for(int i=p+1; i<=q-2; i++){
	            if(i%2 == 0){
	                sum += B[i];
	            }else{
	                sum -= B[i];
	            }
	        }
	        cout<<sum<<endl;
	    }
	}
	return 0;
}
