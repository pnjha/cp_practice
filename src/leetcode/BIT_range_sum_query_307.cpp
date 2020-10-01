class NumArray {
public:
    NumArray(vector<int>& nums) {
        
        arr = nums;
        bit.clear();
        bit.resize(nums.size()+1,0);
        
        for(int i = 0;i<nums.size();i++){
            initialize_bit(i+1,nums[i]);    
        }     
    }
    
    void initialize_bit(int index, int val){
        // print_bit();
        int n = bit.size();
        
        while(index<n){
            bit[index] += val;
            index = index + (index&(-index));
        }
        // print_bit();
    }
    
    void update(int index, int val) {
        // cout<<"start update: \n";
        // print_bit();
        int n = bit.size(), diff = val-arr[index];
        arr[index] = val;
        index++;
        while(index<n){
            // cout<<index<<"\n";
            bit[index] += diff;
            index = index + (index&(-index));
        }
        // print_bit();
        // cout<<"end update\n";
    }
    
    int query(int index){
        // cout<<"query start\n";
        int sum = 0;
        while(index>0){
            sum += bit[index];
            index = index - (index&(-index));
        }
        // cout<<"query end\n";
        return sum;
    }
    
    int sumRange(int i, int j) {
        
        return (query(j+1) - query(i)); 
    }
    
private:
    vector<int> bit;
    vector<int> arr;
    
    void print_bit(){
        for(int i = 0;i<bit.size();i++)
            cout<<bit[i]<<" ";
        cout<<"\n";
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */