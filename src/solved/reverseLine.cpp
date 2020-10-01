#include<bits/stdc++.h>

using namespace std;


void reverseWords(string &A) {
    
    string str = "";
    bool isSpace = false;
    
    for(int i = 0;i<A.size();i++){
        // cout<<str<<"\n";    
        if(A[i]==' '&&isSpace==true){
            str += A[i];
            isSpace = false;
        }else if(A[i]!=' '){
            str += A[i];
            isSpace = true;
        }
    }
    
    // cout<<str<<"\n";

    A = str;
    str = "";

    // cout<<A<<"\n";

    string temp = "";

    for(int i=0;i<A.size();i++){
        // cout<<"herew: "<<A[i]<<"\n";
        if(A[i]!=' '){
            temp += A[i];
        }else{
            if(str.length()!=0)
                str = temp+" "+ str;
            else
                str = temp;
            temp = "";
        }
    }    

    if(str.length()!=0)
        str = temp +" "+ str;
    else
        str = temp;

    // cout<<"Ans: "<<str<<"\n";
    A = str;
}


int main(){

    string str = "j";
    reverseWords(str);
    cout<<str<<"\n";
    return 0;
}