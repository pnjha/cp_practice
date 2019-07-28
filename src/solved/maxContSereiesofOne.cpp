#include<bits/stdc++.h>

using namespace std;

vector<int> maxone(vector<int> &A, int B) {
    
    vector<int> summary;
    deque<int> zeroindex;
    
    int count = 0,sindex = -1,eindex = -1,msf = INT_MIN,max = 0;
    int nextindex,start,end;

    for(int i=0;i<A.size();i++){
        
        if(A[i]==0)
            summary.push_back(0);
        else{
            while(A[i]==1){
                count++;
                i++;
            }
            summary.push_back(count);
            count=0;
            i--;
        }    
    }

    for(int i=0;i<summary.size();i++)
        cout<<summary[i]<<" ";
    cout<<"\n";

    int temp = B;

    for(int i=0;i<summary.size();i++){

        while(temp){
            if(summary[i]==0){
                zeroindex.push_back(i);
                temp--;
                if(i-1>=0)
                    max = summary[i-1];
                if(i+1<summary.size())
                    max += summary[i+1];
                max += 1;
            }else{
                max += summary[i];
            }
            i++;

            if(temp==0&&i+1<summary.size()&&summary[i+1]!=0)
                max += summary[i+1];
        }        



        if(max>msf){
            cout<<"msf: "<<msf<<" "<<"max: "<<max<<"\n";
            msf = max;
            start = zeroindex.front();
            end = zeroindex.back();
        }
        
        if(start-1>=0){
            max = max - summary[start-1]-1;
        }

        cout<<"here max: "<<max<<"\n";

        temp = 1;
        if(zeroindex.back()+1<summary.size()&&
            summary[zeroindex.back()+1]!=0)
            i = zeroindex.back()+2;
        else
            i = zeroindex.back()+1;

        cout<<"here i: "<<i<<"\n";

        zeroindex.pop_front();
    }

    vector<int> ans;

    cout<<"start: "<<start<<" end: "<<end<<"\n";

    if(start-1>=0)
        ans.push_back(start-1);

    for(int i=start;i<=end;i++){
        
        if(summary[i]==0)
            ans.push_back(i);
        else{
            temp = 0;
            while(temp < summary[i]){
                ans.push_back(i+temp);
                temp++;
            }
        }

    }

    if(end+1<summary.size()&&summary[end+1]!=0)
        ans.push_back(end+1);

    return ans;
}


int main(){

    vector<int> arr;
    
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);

    vector<int> ans;

    int b = 1;

    ans = maxone(arr,b);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"\n";

    return 0;
}
