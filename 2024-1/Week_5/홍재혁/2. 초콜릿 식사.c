#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int K;
	scanf("%d", &K);

	int c = 2;
	for(int i=0;i<21;i++)
	{
		if (c >= K)
			break;
		c *= 2;
		
	}
	
		
	int ansC = c;
	int cnt = 0;
	int ans = 0;
	
	while (1)
	{
		
		if (ans == K)	//2로 나누면서 ans에 더한 값이 K랑 같으면 탈출
			break;
		else if (ansC == K)	//나온 c값이 K랑 같다면 탈출
			break;

		
		ansC = ansC / 2;	//계속 2로 나눠줌
		if ((ans + ansC) > K)	//2로 나눈 수와 ans를 더했을 때 K값보다 커지면 넘어감
		{
			cnt++;
			continue;
		}
		else
		{
			ans += ansC;	
			cnt++;
		}
		
	}

	printf("%d %d", c, cnt);

	return 0;
}