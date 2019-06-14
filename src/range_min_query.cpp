// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

#include<bits/stdc++.h>

using namespace std;

int min(int a,int b){
    return a>b?b:a;
}


void update(vector<int>& tree, vector<int>& arr,int tree_index,int start,int end,int index,int value){
    
    if(start==end){
        arr[index] = value;
        tree[tree_index] = value;
    }else{
        int mid = (int)((start+end)/2);
        
        if(start<=index && index<=mid){
            update(tree,arr,tree_index*2,start,mid,index,value);    
        }else{
            update(tree,arr,tree_index*2+1,mid+1,end,index,value);    
        }
        
        tree[tree_index] = min(tree[tree_index*2],tree[tree_index*2+1]);
    }
    
}


int query(vector<int>& tree, vector<int>& arr,int tree_index,int start,int end, int left, int right){
    
    // cout<<start<<" "<<end<<" "<<left<<" "<<right<<"\n";
    
    if(start>right || end<left){
        
        return 100005;
    }else if(start>=left && right>=end){
        // cout<<start<<" "<<end<<"\n";
        // cout<<"tree["<<tree_index<<"]: "<<tree[tree_index]<<"\n";
        return tree[tree_index];
    }

    int mid = (int)((start+end)/2);
    
    int left_val = query(tree,arr,tree_index*2,start,mid,left,right);
    int right_val = query(tree,arr,tree_index*2+1,mid+1,end,left,right);
    
    return min(left_val, right_val);

}

void build_tree(vector<int>& tree, vector<int>& arr,int tree_index,int start,int end){
    
    if(start==end){
        tree[tree_index] = arr[start];
    }else{
        int mid = (int)((start+end)/2);
        build_tree(tree,arr,tree_index*2,start,mid);
        build_tree(tree,arr,tree_index*2+1,mid+1,end);
        tree[tree_index] = min(tree[tree_index*2], tree[tree_index*2+1]);
    }
}

int main(){
    
    int n,q,a,b;
    string query_type = "";
    cin>>n>>q;
    
    vector<int> arr(n+1,0);
    vector<int> tree(4*n, 0);
    
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }
    
    build_tree(tree,arr,1,1,n);
    
    // for(int i = 0;i<tree.size();i++)
    //     cout<<tree[i]<<" ";
    // cout<<"\n";
    
    for(int i = 0;i < q;i++){
        cin>>query_type>>a>>b;
        
        if(query_type == "q"){
            // cout<<"i: "<<i<<"\n";
            cout<<query(tree,arr,1,1,n,a,b)<<"\n";
        }else{
            update(tree,arr,1,1,n,a,b);
        }
    }
    
    return 0;
}