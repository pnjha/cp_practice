#include<bits/stdc++.h>

using namespace std;

int to_integer(const string A) {
    
    set<string> number;
    for(int i=0;i<10;i++){
        // cout<<to_string(i)<<"\n";
        number.insert(to_string(to_string(i)[0]));
    }
    
    bool isNegative = false;
    
    int index = 0,counter=0;
    
    if(A[0]!='+'&&A[0]!='-'&&number.find(to_string(A[0]))==number.end()||A[0]=='-'&&number.find(to_string(A[1]))==number.end()||
            A[0]=='+'&&number.find(to_string(A[1]))==number.end())
        return 0;

    for(int i=0;i<A.length();i++){
        if(number.find(to_string(A[i]))==number.end()){
            // cout<<to_string(A[i])<<"\n";

            if(A[i]=='-'){
                isNegative = true;
            }else{
                isNegative = false;
            }
        }else{

            index = i;
            break;
        }
    }
    
    for(int i=index;i<A.length();i++){
        
        if(number.find(to_string(A[i]))!=number.end()){
            
            counter++;
        }else{
            break;
        }
    }
    
    // cout<<counter<<" "<<index<<"\n";

    int ans = 0,pos = 1;
    
    if(counter == 0)
        return 0;
    else{
        
        for(int i = index+counter-1;i>=index;i--){
            // cout<<ans<<"\n";
            ans += (A[i]-'0')*pos;
            pos *= 10;
        }
        if(isNegative)
            ans *= -1;
            
        return ans;    
    }    
       
}

int main(){

    const string str = "- 5";

    int k = to_integer(str);

    cout<<k<<"\n";

    return 0;
}