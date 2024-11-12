#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max(a,b) (a)>(b)? (a):(b)

int dp[101][100001] = { 0 };
int w[101];
int v[101];

int main()
{
	
	int N, K;
	scanf("%d %d", &N, &K);


	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &w[i],&v[i]);
	}

	for (int i = 0; i <= K; i++)
	{
		dp[0][i] = 0;
	}
	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 0;
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int wi = w[i];
			int vi = v[i];

			if (wi > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				int a = dp[i - 1][j];
				int b = dp[i - 1][j - wi] + vi;
				dp[i][j] = max(a, b);
			}
		}
	}
	printf("%d", dp[N][K]);

	return 0;
}