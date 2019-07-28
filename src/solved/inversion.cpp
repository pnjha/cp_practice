vector<int> merge(vector<int>left, vector<int>right, int &counter){
    vector<int> result;

    vector<int>::iterator leftitr=left.begin();
    vector<int>::iterator rightitr=right.begin();

    int index=0;

    while(leftitr!=left.end()||rightitr!=right.end()){

        if(leftitr==left.end()||(rightitr!=right.end() && *rightitr<*leftitr)){
            result.push_back(*rightitr);
            rightitr++;
            counter+=left.size()-index;

        }else{
            result.push_back(*leftitr);
            leftitr++;
            index++;

        }
    }

    return result;
}

vector<int> mergesort(vector<int> A, int &counter){

    int N=A.size();
    if(N==1)return A;

    vector<int> left(A.begin(),A.begin()+N/2);
    vector<int> right(A.begin()+N/2,A.end());

    left = mergesort(left,counter);
    right = mergesort(right,counter);


    return merge(left, right, counter);

}

int Solution::countInversions(vector<int> &A) {
    int counter = 0;
    mergesort(A,counter);
    
    return counter;
    
}
