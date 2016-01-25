#include <iostream>
#include <cmath>
#include <vector>
#define max(a,b) ((a)>(b)?(a):(b));
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int> > matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
	for (int i = n-1; i >= 0; --i)
	{
		for (int j = 0; j <= n-1; ++j)
		{
			dp[i][j] = matrix[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	cout << dp[0][0] << endl;
#ifndef ONLINE_JUDGE
	fclose(stdout);
	fclose(stdin);
	system("out.txt");
#endif


}