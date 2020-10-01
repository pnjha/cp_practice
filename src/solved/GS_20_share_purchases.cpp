// https://raw.githubusercontent.com/hrudwik/Data_structures/master/Companies/Goldmaan%20Sachs/Previously%20asked%20programs/Share%20Purchases/main.cpp

// C/C++ Solution of Share Purchase problem
#include<bits/stdc++.h>

using namespace std;

int CountTimePeriodOnWhichTheseThreeSharesAreInvested(vector<char> str)
{
  int n = str.size();
  if(n<3)
    return 0;
  int count = 0, s=0, e = s; // sliding window 's' is start index 'e' is end index of the current window
  int a=0,b=0,c=0; //counters of A,B,C shares respectively

  while(s<=n-3 && e<=n-1)
  {
    if(str[e] == 'A')
      a++;
    else if(str[e] == 'B')
      b++;
    else if(str[e] == 'C')
      c++;
    
    while(a>0 && b>0 && c>0 && s<=n-3 && e<=n-1)
    {
      // suppose, [ABC]BCA  here total 4 possible combinations are ABC,ABCB, ABCBC, BACBCA. (n-e = 6-2=4)
      count += (n - e);
      s++;

      if(str[s-1] == 'A')
        a--;
      else if(str[s-1] == 'B')
        b--;
      else if(str[s-1] == 'C')
        c--;
    }
    e++;
  }

  return count;
}

// Driver program to test above functions 
int main() 
{ 
  //string s = "ABCCBA";
  //string s = "PQACBA";
  string s = "ABBCZBAC";
  vector<char> str(s.begin(), s.end());
  cout<<CountTimePeriodOnWhichTheseThreeSharesAreInvested(str)<<endl;

	return 0; 
} 