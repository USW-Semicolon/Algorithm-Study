/*
동그라미 K값이 있는 경우
=> 1~K까지 경로 경우의 수 * K~N*M까지 경로 경우의 수
K값이 없는 경우 => 1~N*M까지 경로 경우의 수
이동방향은 오른쪽, 아래 고정
dp[i][j] => i행j열까지 갈 수 있는 모든 경로의 경우의 수
*/
#include<iostream>
#define MAX_SIZE 15
using namespace std;
int matrix[MAX_SIZE][MAX_SIZE] = { 0, };
int dp[MAX_SIZE][MAX_SIZE] = { 0, };
int N, M, K;
void solve() {
        dp[1][1] = 1;
        if (K != 0) {
                int x, y, cnt = 1;
                //K위치 구하기
                for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= M; j++) {
                                if (cnt == K) { x = i; y = j; }
                                cnt++;
                        }
                }
                //1~K까지 경로 경우의 수 * K~N*M까지 경로 경우의 수
                for (int i = 1; i <= x; i++) {
                        for (int j = 1; j <= y; j++)
                                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
                int tmp = dp[x][y]; 
                //초기화
                for (int i = 1; i <= x; i++) {
                        for (int j = 1; j <= y; j++) dp[i][j] = 0;
                }
                dp[x][y] = 1;
                for (int i = x; i <= N; i++) {
                        for (int j = y; j <= M; j++) {
                                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                        }
                }
                cout << tmp * dp[N][M] << endl;
        }
        else {
                for (int i = 1; i <= N; i++) {
                        for (int j = 1; j <= M; j++)
                                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
                cout << dp[N][M] << endl;
        }
}
int main()
{
        cin >> N >> M >> K;
        solve();
}