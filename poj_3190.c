#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Section{
	int index;
	int start;
	int end;
	int stall;
	bool operator<(const Section& b) const{
		return start < b.start;
	}
};
bool cmp(const Section & a, const Section&b){
	return a.index < b.index;
}
struct Stall{
	int stall;
	int end;
	bool operator<(const Stall &b)const{
		return end > b.end;
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
	vector<Section> sec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> sec[i].start >> sec[i].end;
		sec[i].index = i;
		sec[i].stall = 0;
	}
	sort(sec.begin(), sec.end());
	priority_queue<Stall> que;
	int stall = 0;
	for (int i = 0; i < sec.size(); ++i)
	{
		if (!que.empty())
		{
			Stall s = que.top();
			if (sec[i].start > s.end)
			{
				sec[i].stall = s.stall;
				que.pop();
			}
			else
			{
				sec[i].stall = ++stall;
				
			}
			Stall s_temp;
			s_temp.stall = sec[i].stall;
			s_temp.end = sec[i].end;
			que.push(s_temp);
			
		}
		else
		{
			sec[i].stall = ++stall;
			Stall s_temp;
			s_temp.stall = sec[i].stall;
			s_temp.end = sec[i].end;
			que.push(s_temp);

		}
	}
	sort(sec.begin(), sec.end(),cmp);
	cout << stall << endl;
	for (int i = 0; i < sec.size(); ++i)
	{
		cout << sec[i].stall << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
}