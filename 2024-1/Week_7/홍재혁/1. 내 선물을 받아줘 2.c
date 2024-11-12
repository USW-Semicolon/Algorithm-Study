#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int cnt = 0;
	int N;
	char sen[1001];
	scanf("%d", &N);
	scanf("%s", sen);

	for (int i = 0; i < N; i++)
	{
		if (sen[i] == 'E' && sen[i + 1] == 'W')
			cnt++;
	}
	printf("%d", cnt);


	return 0;
}