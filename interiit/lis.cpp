/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int debug=0;

template<typename T>
void print(T v)
{
    cout << v << "  ";
}

// O(n2)
int computeLIS(vector<int> &sequence)
{
    vector<int> LIS(sequence.size(),1);
    
    int maxLISSequence = 0;
    
    for(int i=0;i<sequence.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(sequence[j] <= sequence[i])
            {
                if(1 + LIS[j]> LIS[i])
                    LIS[i] = 1+LIS[j];
            }
        }
        
        maxLISSequence = max(maxLISSequence,LIS[i]);
    }
    
    if(debug)
    {
        for_each(LIS.begin(),LIS.end(),print<int>);
        cout << endl;
    }
    
    return maxLISSequence;
}

int binary_search(vector<int> &A,int K)
{
    int start=0;
    int end = A.size()-1;
    
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(A[mid]==K)
            return mid;
        else if(mid-1>=0 && A[mid]>K && A[mid-1]<K)
            return mid;
        else if(mid+1<A.size() && A[mid]<K && A[mid+1]>K)
            return mid+1;
        else if(A[mid]>K)
            end = mid-1;
        else
            start = mid+1;
    }
    
    return -1;
}

//O(nlogn)
int computLISModified(vector<int> &sequence)
{
    // LISArray[0] = contain elements 
    // LISArray[1] = will containe indexes corresponding 
    // to the element 
    vector<vector<int>> LISArray(2,vector<int>(0));
    vector<int> parentReference(sequence.size(),-1);
    
    for(int i=0;i<sequence.size();i++)
    {
        int element = sequence[i];
        if(LISArray[0].size()==0)
        {
            LISArray[0].push_back(element);
            LISArray[1].push_back(i);
        }
        else
        {
            int sizeofLISArray = LISArray[0].size();
            int indextoreplace;
            // compare with first element of 
            // subsequence found till the point 
            if(LISArray[0][0]>element)
            {
                LISArray[0][0] = element;
                LISArray[1][0] = i;
            }
            // compare with last element of 
            // subsequences found till the point
            else if(LISArray[0][LISArray[0].size()-1]<element)
            {
                parentReference[i] = LISArray[1][LISArray[1].size()-1];
                LISArray[0].push_back(element);
                LISArray[1].push_back(i);
            }
            // finding a best place to >= elelemnt 
            // to place the element 
            // if we replace the greater value 
            // than the current one then the 
            // chances of getting higher subsequences 
            // is more 
            else
            {
                indextoreplace = binary_search(LISArray[0],element);
                LISArray[0][indextoreplace] = element;
                LISArray[1][indextoreplace] = i;
                if(indextoreplace>0)
                    parentReference[i] = LISArray[1][indextoreplace-1];
            }
        }
        
        // if(debug)
        // {
        //     cout << " LIS ARRAY ELEMENT " << endl;
        //     for(auto a:LISArray[0])
        //     {
        //         cout << a << "  ";
        //     }
        //     cout << endl;
        //     cout << " LIS ARRAY INDEX " << endl;
        //     for(auto a:LISArray[1])
        //     {
        //         cout << a << "  ";
        //     }
        //     cout << endl;
        // }
    }
    
    int maximumLISValue = LISArray[0].size();
    
    if(debug)
    {
        for_each(parentReference.begin(),parentReference.end(),print<int>);
        cout << endl;
    }
    
    // marking all nodes which are -2 
    // are vistied 
    // start with last element index from parent array 
    // go to till index having value -1 
    // if encountered any -2 value it means its not starting of any subsequences 
    
    int sizeofParentArray = parentReference.size()-1;
    vector<vector<int>> allsubsequences;
    vector<int> parSubsequences;
    vector<int> vistiedSubsequences(parentReference.size(),false);
    
    while(sizeofParentArray>=0)
    {
        // if(vistiedSubsequences[sizeofParentArray]==true) 
        // {
        //     sizeofParentArray--;
        //     continue;
        // }
        
        parSubsequences.clear();
        int indextoVisit = parentReference[sizeofParentArray];
        if(indextoVisit==-1)
        {
            parSubsequences.push_back(sequence[sizeofParentArray]);
            reverse(parSubsequences.begin(),parSubsequences.end());
            allsubsequences.push_back(parSubsequences);
            
            vistiedSubsequences[sizeofParentArray] = true;
            sizeofParentArray--;
            continue;
        }
        int tempIndex = sizeofParentArray;
        do
        {
            parSubsequences.push_back(sequence[tempIndex]);
            vistiedSubsequences[tempIndex] = true;
            tempIndex = indextoVisit;
            indextoVisit = parentReference[tempIndex];
            
        }while(tempIndex!=-1);
        
        if(parSubsequences.size()>0)
        {
            reverse(parSubsequences.begin(),parSubsequences.end());
            allsubsequences.push_back(parSubsequences);
            parSubsequences.clear();
        }
        
        sizeofParentArray--;
    }
    
    if(debug)
    {
        for(auto a:allsubsequences)
        {
            for_each(a.begin(),a.end(),print<int>);
            cout << endl;
        }
    }
    cout << " Count of Distinct LIS nlogn " << allsubsequences.size() << endl;
    return maximumLISValue;
}

int main()
{
    vector<int> sequence;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(sequence));
    
    
    
    //cout << " Maximum LIS Sequence " << computeLIS(sequence) << endl; 
    
    if(debug)
    {
        cout << " Input " << endl;
        for_each(sequence.begin(),sequence.end(),print<int>);
        cout << endl;
    }
    
    cout << " Maximum LIS Sequence nlogn (put debug =1 so get  all subsequences) " << computLISModified(sequence) << endl; 
    
    
    return 0;
}

/*
Input 1:
6 21 37 45 27 23 66 9 17 83 59 25 38 63 25 1 37 53 100 80 51 69 72 74 32 82 31 34 95
Output 1:

Input 2:
10 22 9 33 21 50 41 60 80 6
Output 2:
12
-----------------------
 Maximum LIS Sequence 12
-1  0  1  2  1  1  3  0  7  6  3  8  11  12  8  -1  14  16  17  17  16  20  21  22  14  23  14  26  25  
9  17  25  37  51  69  72  74  82  95  
9  17  25  31  34  
9  17  25  32  
9  17  25  37  53  80  
9  17  25  37  53  100  
1  
9  17  25  38  63  
21  37  45  59  
21  37  45  66  83  
21  23  
21  27  
6  
 Count of Distinct LIS nlogn 12
 Maximum LIS Sequence nlogn (put debug =1 so get  all subsequences) 11
--------------------------
*/



