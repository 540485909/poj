#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
#ifndef	ONLINE_JUDGE
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n;
	cin>>n;
	vector<int> stripe(n);
	for(int i=0;i<n;++i)
	{
		cin>>stripe[i];
	}
	sort(stripe.begin(),stripe.end());
	double result=0.25;
	for(int i=0;i<stripe.begin();++i)
	{
		result=2*sqrt(result*stripe[i]);
	}
	cout<<setprecision(3)<<result<<endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
}