//https://leetcode.com/problems/next-permutation/submissions/

class Solution {
public:
    void nextPermutation(vector<int>& num) {
        
        if(num.size()<2)
            return;
        
        int i = num.size()-1,j = 0;
        for(;i>=0;i--)
            if(num[i]>num[i-1])
                break;
        
        if(i==0){
            sort(num.begin(),num.end());
            return;
        }
        
        j = i-1;
        
        while(i<num.size()-1&&num[i+1]>num[j])
            i++;
        
        swap(num[j],num[i]);
        
        sort(num.begin()+j+1,num.end());
        
    }
};