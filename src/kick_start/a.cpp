#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

int tc,n,k,cs=1;

inline int no_of_errors(vector<int>& temp){
    // cout<<"hi"<<endl;
    int cnt=0;
    for(int i=0;i<temp.size()-1;i++){
        // cout<<temp[i]<<" ";
        if(temp[i]!=temp[i+1])
            cnt += 1;
        if(cnt>k) return 0;
    }
    
    return 1;
}
int fun(int vec[]){

    int retval = INT_MAX, a=-1,b=-1,cnt = 0,size = 0;
    
    for(int i=1;i < (1<<n) ;i++){
        // cout<<"i "<<i<<endl;
        // vector<int> temp;
        // temp.clear();
        cnt = 0;
        size = 0;
        a=-1,b=-1;

        for(int j=0;j<n;j++){
            if(i & (1<<j)){

                size++;

                if(a == -1) 
                    a = vec[j];
                else{
                    b = a;
                    a = vec[j];
                }

                // temp.push_back(vec[j]);
                if(a != -1 && b!=-1 && a!=b)
                    cnt += 1;
            }
        }
        // cout<<temp.size()<<endl;
        // if(no_of_errors(temp))
        //     if (n-temp.size()<retval)
        //         retval = n-temp.size();

        
    
        if(cnt<=k && retval>n-size){
            retval = n-size;        
        }
    }
    return retval;
}
int main(){
    
    // freopen("in.txt","r",stdin);
    
    scanf("%d",&tc);

    while(tc--){
        scanf("%d %d",&n,&k);
        
        int vec[n] = {0};
        
        for(int i=0;i<n;i++){
            scanf("%d",&vec[i]);
        }

        int ans = fun(vec);
        printf("Case #%d: %d\n",cs,ans);
        cs++;
        
    }
    return 0;
}

/*
Case #1: 3
Case #2: 0
Case #3: 1
Case #4: 2
*/