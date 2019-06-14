#include<bits/stdc++.h>

using namespace std;


int merge(vector<int> &arr,int left,int mid,int right){

    int i = 0,j = 0,k = left,count = 0;
    vector<int> t1;
    vector<int> t2;

    for(int i = left;i<=mid;i++){
        t1.push_back(arr[i]);
    }

    for(int j = mid+1;j<=right;j++){
        t2.push_back(arr[j]);
    }

    while(i<t1.size()&&j<t2.size()){
        
        if(t1[i]<=t2[j]){
            arr[k] = t1[i];
            i++;
            k++;
        }else{
            arr[k] = t2[j];
            count += t1.size()-i;
            j++;
            k++;
            
        }
    }

    while(i<t1.size()){

        arr[k] = t1[i];
        i++;
        k++;
    }

    while(j<t2.size()){
        
        arr[k] = t2[j];
        j++;
        k++;
    }
    
    return count;
}

int mergeSort(vector<int> &arr,int left,int right){

    int mid,count = 0;

    if(left<right){

        mid = left+(right-left)/2;
        // cout<<"First left: "<<left<<" mid: "<<mid<<" right: "<<right<<"\n";
        count += mergeSort(arr,left,mid);
        // cout<<"Second left: "<<left<<" mid: "<<mid<<" right: "<<right<<"\n";
        count += mergeSort(arr,mid+1,right);
        
        count += merge(arr,left,mid,right);

    }
    
    return count;
}


int main() {
    
    int arr[] = {84, 2, 37, 3, 67, 82, 19, 97, 91, 63, 27, 6, 13,
     90, 63, 89, 100, 60, 47, 96, 54, 26, 64, 50, 71, 16, 6, 40, 
     84, 93, 67, 85, 16, 22, 60};
        
    // int arr[] = {59,29};

    vector<int> A(arr, arr + sizeof(arr) / sizeof(arr[0]));

    cout<< mergeSort(A,0,A.size()-1)<<"\n";
    
    return 0;
    
}

/*

vector<int> merge(vector<int>left, vector<int>right, int &counter)
{

    vector<int> result;

    vector<int>::iterator it_l=left.begin();
    vector<int>::iterator it_r=right.begin();

    int index_left=0;

    while(it_l!=left.end() || it_r!=right.end())
    {

        // the following is true if we are finished with the left vector 
        // OR if the value in the right vector is the smaller one.

        if(it_l==left.end() || (it_r!=right.end() && *it_r<*it_l) )
        {
            result.push_back(*it_r);
            it_r++;

            // increase inversion counter
            counter+=left.size()-index_left;
        }
        else
        {
            result.push_back(*it_l);
            it_l++;
            index_left++;

        }
    }

    return result;
}

vector<int> merge_sort_and_count(vector<int> A, int &counter)
{

    int N=A.size();
    if(N==1)return A;

    vector<int> left(A.begin(),A.begin()+N/2);
    vector<int> right(A.begin()+N/2,A.end());

    left=merge_sort_and_count(left,counter);
    right=merge_sort_and_count(right,counter);


    return merge(left, right, counter);

}

int Solution::countInversions(vector<int> &A) {
    int counter = 0;
    merge_sort_and_count(A,counter);
    
    return counter;
    
}


*/