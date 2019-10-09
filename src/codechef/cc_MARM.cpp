#include<stdio.h>
#include<iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include<cstring>
#define int long long int

using namespace std;

int32_t main(){
    
    freopen("input.txt","r",stdin);
    
    int tc,n,q,cs=1;
    long long int k;
    
    scanf("%lld",&tc);

    while(tc--){
    
        scanf("%lld %lld",&n,&k);
    
        int arr[n];
    
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }

        // k--;

        long long tk = (k/n)%3;
        // tk = tk % 3;
        int limit_k = k%n;

        if(tk==0){
            for(int i=0;i<limit_k;i++){
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];
            }    
        }
        if(tk==1){
            
            for(int i=0;i<n;i++){
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];    
            }
            for(int i=0;i<limit_k;i++)
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];    
        }
        if(tk==2){
            
            for(int i=0;i<n;i++){
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];    
            }
            for(int i=0;i<n;i++){
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];    
            }
            for(int i=0;i<limit_k;i++)
                arr[i] = arr[i%n] ^ arr[n-1-(i%n)];
        }
        
        for(int i=0;i<n;i++){
            printf("%lld ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}