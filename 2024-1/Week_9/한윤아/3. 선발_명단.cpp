#include<iostream>
#include<cstring>
#define max(a,b)(a>b?a:b)
using namespace std;
int N, ans;
int status[11][11];
int visited[11];
void solve(int sum, int idx) {
        if (idx == 11) {
                ans = max(ans, sum);
                return;
        }
        for (int i = 0; i < 11; i++) {
                if (status[idx][i] != 0 && visited[i] == 0) {
                        visited[i] = 1;
                        solve(sum + status[idx][i], idx + 1);
                        visited[i] = 0;
                }
        }
        return;
}
int main()
{
        cin >> N; //테스트 케이스 개수
        while (N > 0) {
                for (int i = 0; i < 11; i++) {
                        for (int j = 0; j < 11; j++) cin >> status[i][j];
                }
                memset(visited, 0, sizeof(visited));
                ans = 0;
                solve(0, 0);
                cout << ans << endl;
                N--;
        }
}