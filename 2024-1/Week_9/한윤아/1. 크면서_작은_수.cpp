#include<iostream>
#include<string>
#include<typeinfo>
#define min(a,b)(a<b?a:b)
#define NUM_SIZE 6
#define INF 1000000
using namespace std;
string X;
int len, visited[NUM_SIZE] = { 0, }, ans = INF;
void solve(string tmp, int idx) {
        if (tmp == X) return;
        if (idx == len) {
                if (tmp > X) {
                        ans = min(ans, stoi(tmp));
                        return;
                }
        }
        for (int i = 0; i < len; i++) {
                if (visited[i] == 0) {
                        visited[i] = 1;
                        solve(tmp + X[i], idx + 1);
                        visited[i] = 0;
                }
        }
        return;
}
int main()
{
        cin >> X;
        len = X.length();
        solve("", 0);
        if (ans != INF) cout << ans << endl;
        else cout << 0 << endl;
}