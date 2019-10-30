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

/*

 def unknownStartDay(day, month, year):
            def hasLeapDay(year):
                return 1 if year % 4 == 0 and year % 100 != 0 or year % 400 == 0 else 0
            
            dayNames = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
            daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
            # days since 31, 12, 1970
            def daysSinceStart(day, month, year):
                numDays = 0
                for y in range(year - 1, 1970, -1):
                    numDays += 365 + hasLeapDay(y)
                numDays += sum(daysInMonth[:month-1])
                numDays += day 
                if month > 2:    
                    numDays += hasLeapDay(year)
                return numDays
            
            knownStart = daysSinceStart(14,9,2019)
            d = daysSinceStart(day, month, year) 
            return dayNames[ (d - knownStart) % 7]*/