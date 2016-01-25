#include <iostream>
#include <algorithm>
using namespace std;
struct Interval{
	int start_time;
	int end_time;
	int efficiency;
	bool operator<(Interval& a)
	{
		return efficiency<a.efficiency;
	}
	
};
int main()
{
#ifnded ONLINE_JUDGE
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int N,M,R;
	cin>>N>>M>>R;
	vector<Interval> milk(M);
	for(int i=0;i<M;++i)
	{
		cin>>milk[i].start_time>>milk[i].end_time>>milk[i].efficiency;
		milk[i].end_time+=R;
	}
	vector<int> dp(M,0);
	sort(milk.begin(),milk.end());
	for(int i=0;i<M;++i)
	{
		dp[i]=milk[i].efficiency;
		for(int j=0;j<i;++j)
		{
			if(milk[j].end_time<=milk[i].start_time)
			{
				dp[i]=max(dp[i],dp[j]+milk[i].efficiency);
			}
		}
	}
	cout<<*max_element(dp,dp+M)<<endl;
#ifndef ONLINE_JUDGE
    fclose(stdout);
	fclose(stdin);
	system("out.txt");
#endif
	return 0;
}