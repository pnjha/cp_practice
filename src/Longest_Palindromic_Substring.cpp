#include<bits/stdc++.h>

using namespace std;


string longestPalindrome(string A) {
    
    int left,right,msf = INT_MIN,len = 0,index;
    string pstring,temp = "";
    
    for(int i=0;i<A.length();i++){
        
        temp = "";
        left = i;
        right = i;
        len = 0;
        
        while(left>=0&&right<A.length()&&A[left]==A[right]){
            
            if(left==right){
                len++;
                temp = A[left];
            }
            else{
                temp += A[right];
                temp = A[left] + temp;
                len += 2;
            }
            
            left--;
            right++;
        }
        
        // cout<<"Odd length: "<<temp<<"\n";

        if(len>msf){
            msf = len;
            pstring = temp;
            index = left++;
        }else if(len==msf){
            if(++left<index){
                msf = len;
                pstring = temp;
                index = left;
            }
        }
        
        temp = "";
        left = i;
        right = i+1;
        len = 0;
        
        while(left>=0&&right<A.length()&&A[left]==A[right]){
            temp += A[right];
            temp = A[left] + temp;
            len += 2;
            right++;
            left--;
        }
        
        // cout<<"Even length: "<<temp<<"\n";
        // cout<<"len: "<<len<<" msf: "<<msf<<"\n";
        if(len>msf){
            msf = len;
            pstring = temp;
            index = left++;
        }else if(len==msf){
            if(++left<index){
                msf = len;
                pstring = temp;
                index = left;
            }
        }
    }
    return pstring;
}

int main(){

    string str = "abb";

    cout<<longestPalindrome(str)<<"\n";

    return 0;
}
