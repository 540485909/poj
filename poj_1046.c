#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX_N  4000
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int CD[MAX_N*MAX_N];
int cmp(const void *a, const void *b)
{
	return (*(int*)a) - (*(int*)b);
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
		}
		int j;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				CD[i*n + j] = C[i] + D[j];
			}
		}
		qsort(CD, n*n, sizeof(int), cmp);
		long long res = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				int cd = -(A[i] + B[j]);

				
				res += upper_bound(CD, CD + n*n, cd) - lower_bound(CD, CD + n*n, cd);
			}
		}
		printf("%d\n", res);

	}
	
	
}