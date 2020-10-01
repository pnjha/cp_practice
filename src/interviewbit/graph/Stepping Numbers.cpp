#include<bits/stdc++.h>

using namespace std;

set<int> ans;
vector<int> a,b;
int max_len,min_len;

void dfs(int A,int B, int len, int num){
    
    if(len>max_len) return;
    if(num>=A && num<=B) ans.insert(num);
    
    int last_digit = num%10;
    for(int i = 0;i<10;i++){
        if(len >= min_len-1){            
            if(abs(last_digit-i)==1 && num*10+i>=A && num*10+i<=B){
                dfs(A, B, len+1, num*10+i);
            }
        }else{
            if(abs(last_digit-i)==1 && i>=a[len] && num*10+i<=B){
                dfs(A, B, len+1, num*10+i);
            }
        }
    }
}

vector<int> stepnum(int A, int B) {
    
    ans.clear(),a.clear(),b.clear();
    
    int temp = A;
    
    if(A>B){
        temp = A;
        A = B;
        B = temp;
    }

    temp = A;
    if(temp){
        while(temp){
            a.push_back(temp%10);
            temp = temp/10;
        }
    }else{
        a.push_back(0);
    }
    temp = B;
    while(temp){
        b.push_back(temp%10);
        temp = temp/10;
    }
    max_len = b.size();
    min_len = a.size();
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i = 1;i<10;i++){
       if(i>=a[0] && i<=B){
            cout<<i<<"\n";
            dfs(A,B,1,i); 
       }
    }
    
    return {ans.begin(),ans.end()}; 
}

int main(){

    vector<int> x = stepnum(213,231141);

    for(int i = 0;i<x.size();i++) cout<<x[i]<<" ";
    cout<<"\n";

    return 0;
}