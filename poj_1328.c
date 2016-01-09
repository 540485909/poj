#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;
int n, d;
const int N = 1000;
struct Section{
	double left;
	double right;
	bool operator<(const Section&b)const
	{
		return left < b.left;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int test_case = 0;
	while (cin >> n >> d&&d != 0)
	{
		cout << "Case " << ++test_case << ": ";
		vector<Section> s(n);
		int x, y;
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> x >> y;
			if (y > d)
			{
				result = -1;
				continue;
			
			}
			double r = sqrt((double)d*d - y*y);
			s[i].left = x - r;
			s[i].right = x + r;

		}
		if (result == -1)
		{
			cout  << result << endl;
			continue;
		}
		sort(s.begin(), s.end()); 
		double end = -numeric_limits<double>::max();

	
		for (int i = 0; i < s.size(); ++i)
		{
			if (end<s[i].left)
			{
				end = s[i].right;
				result++;
			}
			else if (end>s[i].right)
			{
				//narrow down the interval 
				end = s[i].right;
			}
		}
		
		cout  << result << endl;

	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
}