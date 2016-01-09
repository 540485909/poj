#ifndef ONLINE_JUDGE
#endif
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w, h;
int map[32][32];
int sx, sy;
int min_step;
const int direction[4][2] = {
	{ -1, 0 },
	{ 1, 0 },
	{ 0, -1 },
	{ 0, 1 },
};

void dfs(const int& x, const int& y, int step)
{
	if (step >= 10 || step > min_step)
	{
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x;
		int ny = y;
		// ��ʯͷ���̶��ķ���һֱ��
		while (nx >= 0 && nx < w && ny >= 0 && ny < h)
		{
			switch (map[nx][ny])
			{
			case 0:
			{
				// ������
				nx += direction[i][0];
				ny += direction[i][1];
			}break;
			case 3:
			{
				// ������
				if (step + 1 < min_step)
				{
					min_step = step + 1;
				}
				nx = -1;
			}break;
			case 1:
			{

				// ײ����block
				if (!(nx - direction[i][0] == x && ny - direction[i][1] == y))
				{
					// �м��пյأ����ǽ�����block
					// ʯͷ��ʧ
					map[nx][ny] = 0;
					// ����һ����ʯͷ
					dfs(nx - direction[i][0], ny - direction[i][1], step + 1);
					// ��ԭ��ͼ������һ��������
					map[nx][ny] = 1;
				}
				// ��ʼ��һ������
				nx = -1;
			}break;
			default:
				break;
			}
		}

	}
}

///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while (cin >> w >> h, w != 0)
	{
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> map[j][i];
			}
		}
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (2 == map[j][i])
				{
					sx = j;
					sy = i;
					i = h;
					break;
				}
			}
		}

		map[sx][sy] = 0;
		min_step = 11;
		dfs(sx, sy, 0);
		if (min_step > 10)
		{
			min_step = -1;
		}
		cout << min_step << endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}