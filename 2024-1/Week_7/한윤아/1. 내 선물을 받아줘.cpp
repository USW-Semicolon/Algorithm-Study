/*
1xN크기 1차원 배열
E => x+1, W => x-1로 이동
"출발 위치에 관계없이" 구사과가 반드시 선물을 가져갈 수 있는 최소 선물 개수
EEWWEW => 0~3번째에서 출발하면 1, 2번째 EW를 항상 지나감
                   => 4~5번째에서 출발하면 4, 5번째 EW를 항상 지나감
                   =>> E에서 W로 바뀌는 순간을 확인
*/
#include<iostream>
int N, cnt = 0;
char road[1000];
int main()
{
        using namespace std;
        cin >> N;
        for (int i = 0; i < N; i++) {
                cin >> road[i];
                if (i > 0 && (road[i - 1] == 'E' && road[i] == 'W')) cnt++;
        }
        cout << cnt;
}