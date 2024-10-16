#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    int rows, cols, wait;
    scanf("%d %d", &cols, &rows);
    scanf("%d", &wait);

    if ((rows * cols) < wait)
    {
        printf("0");
        exit(0);
    }



    int arr[rows][cols]; // 2차원 배열 선언
    int num = 1; // 배열에 채울 숫자 초기화
    int x = rows - 1, y = 0; // 왼쪽 아래부터 시작 (행: rows-1, 열: 0)

    // 이동 방향 설정 (시계 방향: 위 -> 오른쪽 -> 아래 -> 왼쪽)
    int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int d = 0; // 방향 인덱스 (0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽)

    // 배열을 0으로 초기화
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = 0;

    for (int i = 0; i < rows * cols; i++) {
        arr[x][y] = num++; // 현재 위치에 숫자 채우기

        // 다음 위치 계산
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        // 범위를 벗어나거나 이미 값이 채워진 경우 방향 전환
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || arr[nx][ny] != 0) {
            d = (d + 1) % 4; // 방향 전환
            nx = x + dir[d][0];
            ny = y + dir[d][1];
        }

        // 다음 위치로 이동
        x = nx;
        y = ny;
    }
    int ax, ay;
    // 배열 출력
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == wait)
            {
                ax = i;
                ay = j;
                break;
            }
        }
    }



    int ansx = ay + 1;
    int ansy = rows - ax;

    printf("%d %d", ansx, ansy);
    return 0;
}
