#O(n^2) dp solution
t=int(input())
for _ in range (t):
    n=int(input())
    a=[]
    a=list(map(int,input().split()))
    lis=[0 for i in range (n)]
    lis[0]=1
    i=1
    j=0
    ans=1
    while (i<len(a)):
        while (j<i):
            if (a[i]>=a[j]):
                lis[i]=max(lis[j]+1,lis[i])
            
            j+=1
        if (lis[i]==0):
            lis[i]=1
        j=0
        ans=max(ans,lis[i])
            
        i+=1
        
    print(ans)