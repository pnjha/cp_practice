#include <bits/stdc++.h>
using namespace std;

vector<string> day = {"Tuesday", "Wednesday", "Thursday", "Friday","Saturday", "Sunday", "Monday"};

long int day_of_week(int d,int m,int y){
    vector<int> num_days = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    long int tdays = 0;
    
    for(int i = 1971;i<y;i++){
        if(i%4==0&&i%100!=0||i%400==0) tdays += 366;
        else tdays += 365;
    }
    if(y%4==0&&y%100!=0||y%400==0) num_days[1] = 29;
    for(int i = 0;i<m-1;i++) tdays += num_days[i];
    
    tdays += d;
    return tdays;
}

int main() {
	int t,d,m,y;
    cin>>t;
    while(t--){
        cin>>d>>m>>y;
        cout<<day[(((day_of_week(d,m,y)-day_of_week(29,10,2019))%7)+7)%7]<<"\n";
    }
	return 0;
}
