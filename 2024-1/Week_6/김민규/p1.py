import sys

def main():
    input = sys.stdin.read
    data = input().strip().split('\n')
    
    # 첫 번째 줄에서 N, S, M을 읽어옵니다.
    N, S, M = map(int, data[0].split())
    
    # 두 번째 줄에서 볼륨 조절 리스트 V를 읽어옵니다.
    V = list(map(int, data[1].split()))
    

    dp = [[False] * (M+1) for _ in range(N+1)]
    dp[0][S] = True

    for i in range(1, N+1):
        for j in range(M+1):
            if dp[i-1][j]:
                if j+V[i-1] <= M:
                    dp[i][j+V[i-1]] = True
                if j-V[i-1] >= 0:
                    dp[i][j-V[i-1]] = True


                                
    max_volume = -1
    for j in range(M+1):
        if dp[N][j]:
            max_volume = max(max_volume, j)

    print(max_volume)

if __name__ == "__main__":
    main()