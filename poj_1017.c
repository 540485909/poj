#include <iostream>
#include <cmath>
using namespace std;
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int n, p1, p2, p3, p4, p5, p6, x , y;
	int space[4] = {0, 5, 3, 1}; // һ�����ӷ��뼸�� 3 * 3 �����µķ�϶���Է��뼸�� 2 * 2
	while(true)
	{
		cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
		if(p1 == 0 && p2 == 0 && p3 == 0 && p4 == 0 && p5 == 0 && p6 == 0)
		{
			break;
		}
		// ��һ�ηš��Ų��µڶ������ͺš����ͺţ���Ҫ����n������
		n = p4 + p5 + p6 + ceil(p3 / 4.0); // �� 3 * 3 �� package �������ĸ��պã���������ȡ��
		// ���� 4 * 4 ���ͺź� 3 * 3 ���ͺ�֮��ķ�϶���Է��¶��ٸ� 2 * 2 ���ͺ�
		y = 5 * p4 + space[p3 % 4];
		// 2 * 2 ���ͺ�������Щ��϶�������£��ٶ����ļ�������
		if(p2 > y)
		{
			n += ceil((p2 - y) / 9.0); // �������ÿ9���պ�һ������
		}
		// �������ڿ��˶��ٸ� 1 * 1 ��λ��
		x = 36 * n - 36 * p6 - 25 * p5 - 16 * p4 - 9 * p3 - 4 * p2;
		// 1 * 1 ���ͺ�������Щ��϶�������£��ٶ����ļ�������
		if(p1>x)
		{
			n += ceil((p1 - x) / 36.0);
		}
		cout << n << endl;
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}