#include<bits/stdc++.h>

using namespace std;


string convert(string A, int B) {
    
    string str = "";
    
    int i = 0,j = 0,step = 0;
    bool isInside = false;

    while(str.length()!=A.length()){
        // cout<<str<<" "<<B<<" "<<i<<" "<<j<<" \n";
        
        while(A[i]=='*')
        	i++;

        j = i;

        step = 2*B-3;

        cout<<"step: "<<step<<"\n";

        while(j<A.length()&&A[j]!='*'){
    		isInside = true;
            str += A[j];
            A[j] = '*';
            j += step+1;
        }
        cout<<A<<"\n";
        if(isInside)
        	B -= 1;
        isInside = false;
    }
    return str;
}


int main(){

	string str = "ABCDEFGHIJ";

	cout<<convert(str,5)<<"\n";

	return 0;
}