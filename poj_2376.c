#include <iostream>
#include <algorithm>
using namespace std;
int N, T;

struct Cow
{
	int begin;	
	int end;	
};

#define MAX_COWS 25000
Cow cow[MAX_COWS];

bool is_greater(const Cow& a, const Cow& b)
{
	return a.begin < b.begin || (a.begin == b.begin && a.end > b.end);
}

int solve()
{
	int used_cows = 0;
	int end = 0;
	int index = 0;
	while (end < T)
	{
		int begin = end + 1;
 
		for (int i = index; i < N; ++i)
		{
			if (cow[i].begin <= begin)
			{
		
				if (cow[i].end >= begin)
				{
					end = max(end, cow[i].end);
				}
			}
			else
			{
				
				index = i;
				break;
			}
		}

	
		if (begin > end)
		{
			return -1;
		}
		else
		{
			++used_cows;
		}
	}

	return used_cows;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		cin >> cow[i].begin >> cow[i].end;
	}
	sort(cow, cow + N, is_greater);
	cout << solve() << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}