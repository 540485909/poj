#include <iostream>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int t, w;
	cin >> t >> w;

	vector<vector<int> > num(2, vector<int>(t + 1, 0));
	vector<vector<int> > dp(t + 1, vector<int>(w + 1, 0));
	for (int i = 1; i <= t; ++i)
	{
		int a;
		cin >> a;
		num[(a - 1) & 1][i] = 1;
	}
	dp[1][0] = num[0][1];
	dp[1][1] = num[1][1];
	for (int i = 2; i <= t; ++i)
	{
		for (int j = 0; j <= w; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + num[0][i];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[j & 1][i];
			}
			
		}
	}
	cout << dp[t][w] << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;

}