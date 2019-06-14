#include<bits/stdc++.h>

using namespace std;


int seats(string A){
    
    vector<int> startIndex;
    bool flag = false;
    int maxSize = 0,temp= 0,index = -1;
    
    for(int i = 0;i<A.length();i++){
        
        if(A[i]=='x'&&flag){
            temp++;
        }else if(A[i]=='x'&&flag==false){
            temp = 1;
            flag = true;
            index = i;
        }else if(A[i]!='x'){
            if(temp>maxSize){
                maxSize = temp;
                startIndex.clear();
                startIndex.push_back(index);
            }else if(temp==maxSize){
                startIndex.push_back(index);
            }
            temp = 0;
            flag = false;
        }
        
    }

    if(temp>maxSize&&flag){
        startIndex.clear();
        startIndex.push_back(index);
    }else if(temp == maxSize)
        startIndex.push_back(index);

    for(int i = 0;i<startIndex.size();i++)
        cout<<startIndex[i]<<" ";
    cout<<"\n";

    int sIndex = -1,eIndex = -1;
    temp = (startIndex.size()/2);
    
    temp = startIndex[temp];
    sIndex = temp;
    eIndex = temp + maxSize;
    
    cout<<temp<<" "<<maxSize<<" "<<sIndex<<" "<<eIndex<<"\n";

    int ans = 0;
    temp = 0;
    
    for(int i = sIndex-1;i>=0;i--){
        
        if(A[i]=='x'){
            ans += temp;
            temp--;
        }
        temp++;
    }
    
    cout<<"ans: "<<ans<<"\n";
    temp = 0;
    
    for(int i = eIndex;i<A.size();i++){
        
        if(A[i]=='x'){
            cout<<"temp: "<<temp<<"\n";
            ans += temp;
            temp--;
        }
        temp++;
    }
    cout<<"ans: "<<ans<<"\n";
    return ans;
}


int main(){

    string str = "x.x.xx.x.xxx.......x..x.xxx..x.xxx";

    cout<<seats(str)<<"\n";

    return 0;
}