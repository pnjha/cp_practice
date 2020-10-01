using namespace std;
#include <bits/stdc++.h>

long long data[200001];
	    
int main()
{
	int t,debug=0;
	cin >> t;
	
	

	for(int i1=0;i1<t;i1++)
	{

		long long max_len=1;
		long long diff=LONG_MIN;
		
		//memset(data,0,sizeof(data));

		int n,counter=1;
		cin >> n;

		for(int i2=0;i2<n;i2++)
		{
			long long value;
			cin >> value;
			data[i2] = value;
			
			if(debug)
			    cout << " Input " << value << endl;

			if(i2>0)
			{
				if ( diff==LONG_MIN  )
				{
					diff = (data[i2-1] - data[i2]);
					counter++;
				}
				else
				{
					long long current_diff = (data[i2-1] - data[i2]);
					if(current_diff != diff)
					{
						if(counter>max_len)
						{
							max_len = counter;
							if(debug)
							{
							    cout << " prev and curr diff not same Counter Increased " << endl;
							}
						}
						counter=2;
						diff = current_diff;
					}
					else
					{
						counter++;
					}
					
					if(debug)
			        cout << " diff " << diff << " current_diff " << current_diff << " counter " << counter << endl;
				}
				
				if(counter>max_len)
				{
					max_len = counter;
					if(debug)
					{
					    cout << " Counter Increased " << endl;
					}
				}
			}
			
		}

		cout << "Case #" << (i1+1) << ": " << max_len << endl;
	}
}
