#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct data{
	int t;
	int d;
	bool operator<(const data &b){
		return d*1.0/t-b.d*1.0/b.t>0;
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<data> cow(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cow[i].t >> cow[i].d;
	}
	sort(cow.begin(), cow.end());
	long long time = 0;
	long long cost = 0;
	for (int i = 0; i < cow.size(); ++i)
	{
		cost += time*cow[i].d;
		time += 2 * cow[i].t;

	}
	cout << cost << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
}