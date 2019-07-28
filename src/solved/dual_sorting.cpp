// https://practice.geeksforgeeks.org/problems/student-of-the-year/1/?ref=self

bool custom_comparator(const pair<string,int>& v1,const pair<string,int>& v2){
    
    if(v1.second<v2.second)
        return false;
    else if(v1.second == v2.second){
        if(v1.first<v2.first)
            return true;
    }else
        return true;
    
}

vector<pair<string, int>> sortMarks(vector<pair<string, int>> v, int N){
    
    sort(v.begin(),v.end(),custom_comparator);
    return v;
    //Complete the code and return the sorted vector
}
