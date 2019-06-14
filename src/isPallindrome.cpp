#include<bits/stdc++.h>

using namespace std;

int isPalindrome(string B) {
    
    set<char> digit;
    digit.insert('1');digit.insert('2');digit.insert('3');digit.insert('4');
    digit.insert('5');digit.insert('6');digit.insert('7');digit.insert('8');
    digit.insert('9');digit.insert('0');
    
    set<char> alphabet;
    alphabet.insert('a');alphabet.insert('b');alphabet.insert('c');alphabet.insert('d');
    alphabet.insert('h');alphabet.insert('g');alphabet.insert('f');alphabet.insert('e');
    alphabet.insert('i');alphabet.insert('j');alphabet.insert('k');alphabet.insert('l');
    alphabet.insert('p');alphabet.insert('o');alphabet.insert('n');alphabet.insert('m');
    alphabet.insert('q');alphabet.insert('r');alphabet.insert('s');alphabet.insert('t');
    alphabet.insert('x');alphabet.insert('w');alphabet.insert('v');alphabet.insert('u');
    alphabet.insert('y');alphabet.insert('z');
    
    int l,r,isPallindrome = 0;
    
    string A = "";
    
    for(int i=0;i<B.size();i++){
        if(digit.find((B[i]))!=digit.end())
            A += (B[i]);
        else if(alphabet.find((tolower(B[i])))!=alphabet.end()){
            A += (tolower(B[i]));
        }    
    }
    
    cout<<A<<'\n';

    if(A.size()%2==0){
        l = A.size()/2-1;
        r = A.size()/2;
    }else{
        l = A.size()/2-1;
        r = A.size()/2+1;
    }
    
    while(l>=0&&r<=A.size()){
        if(A[l]!=A[r])
            return 0;
        l--;
        r++;
    }
    return 1;
}


int main(){

    string str = "race a Car";

    cout<<isPalindrome(str)<<"\n";

    return 0;
}