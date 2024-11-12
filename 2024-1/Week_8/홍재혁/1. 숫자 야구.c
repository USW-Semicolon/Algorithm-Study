#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int main()
{
    int visit[1000] = { 0 };

    int testcase;
    scanf("%d", &testcase);

    int num, strike, ball;
    for (int i = 0; i < testcase; i++)
    {
        scanf("%d %d %d", &num, &strike, &ball);
        int num1 = num / 100;
        int num2 = (num % 100) / 10;
        int num3 = num % 10;

        //나올 수 있는 숫자의 범위 123~987
        for (int j = 123; j <= 987; j++)
        {
            int s_cnt = 0;
            int b_cnt = 0;

            if (visit[j] == 0)
            {
                int j1 = j / 100;
                int j2 = (j % 100) / 10;
                int j3 = j % 10;
                //같은수가 두개거나 0이 포함되면 X
                if (j1 != j2 && j1 != j3 && j2 != j3 && j1 != 0 && j2 != 0 && j3 != 0)
                {
                    //100의자리
                    if (num1 == j1)
                        s_cnt++;
                    else if (num1 == j2 || num1 == j3)
                        b_cnt++;

                    //10의자리
                    if (num2 == j2)
                        s_cnt++;
                    else if (num2 == j1 || num2 == j3)
                        b_cnt++;

                    //1의자리
                    if (num3 == j3)
                        s_cnt++;
                    else if (num3 == j1 || num3 == j2)
                        b_cnt++;
                }
                else
                    visit[j] = 1;
            }
            //strike나 ball이 입력된 것과 다르면 visit을 1로 바꿈
            if (strike != s_cnt || ball != b_cnt)
                visit[j] = 1;
        }
    }

    int cnt = 0;
    for (int i = 123; i <= 987; i++)
    {
        if (visit[i] == 0)
            cnt++;
    }
    printf("%d", cnt);



    return 0;
}