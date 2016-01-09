#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define INDEX_MAX 512
int map[INDEX_MAX][INDEX_MAX];
bool visited[INDEX_MAX][INDEX_MAX];
struct Meteor
{
	int x, y, t;
};
typedef Meteor P;
const int direction[5][2] = {
	{0,1},
	{0,-1},
	{-1,0},
	{1,0},
	{0,0}
};
Meteor m[50001];
int n;
int last;
int bfs()
{
	memset(visited, false, sizeof(visited));
	queue<P> que;
	P current;
	current.x = 0;
	current.y = 0;
	current.t = 0;
	que.push(current);
	visited[0][0] = true;
	while (!que.empty())
	{
		P p = que.front(); que.pop();
		for (int i = 0; i < 4; ++i)
		{
			current.x = p.x + direction[i][0];
			current.y = p.y + direction[i][1];
			current.t = p.t+1;
			if (current.x>=0&&current.y>=0&&!visited[current.x][current.y]
				&&map[current.x][current.y]>current.t)
			{
				visited[current.x][current.y] = true;
				if (map[current.x][current.y] > last)
				{
					return current.t;
				}
				que.push(current);

			}
			
		}
		

	}
	return -1;
}
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].x >> m[i].y >> m[i].t;

	}
	memset(map, 0x7f, sizeof(map));
	for (int i = 0; i < n; ++i)
	{
		last = max(last, m[i].t);
		for (int j = 0; j < 5; ++j)
		{
			int nx = m[i].x + direction[j][0];
			int ny = m[i].y + direction[j][1];
			if (nx >= 0 && ny >= 0 && map[nx][ny] > m[i].t)
			{
				map[nx][ny] = m[i].t;
			}
		}
	}
	if (map[0][0] == 0)
	{
		return -1;
	}
	else
	{
		cout<<bfs();
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}