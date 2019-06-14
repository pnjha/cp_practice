#include<bits/stdc++.h>

using namespace std;


int evalRPN(vector<string> &A){
    
    stack<int> s;
    int a,b;
    
    for(int i = 0;i<A.size();i++){
        
        if(A[i]!="+"&&A[i]!="*"&&A[i]!="/"&&A[i]!="-"){
            s.push(stoi(A[i],nullptr,10));
        }else if(A[i]=="+"){
            cout<<"here +";
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(a+b);
        }else if(A[i]=="*"){
            cout<<"here *";
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(a*b);
        }else if(A[i]=="-"){
            cout<<"here -";
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            s.push(b-a);
        }else if(A[i]=="/"){
            cout<<"here /";
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            
            s.push((int)(b/a));
        }
        cout<<s.top()<<"\n";
    }
    return s.top();
}


int main(){

    vector<string> exp;
    exp.push_back("4");
    exp.push_back("13");
    exp.push_back("5");
    exp.push_back("/");
    exp.push_back("+");
    // exp.push_back("4");
    cout<<evalRPN(exp)<<"\n";

    return 0;
}