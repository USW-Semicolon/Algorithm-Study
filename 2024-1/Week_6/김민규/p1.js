const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input.push(line.trim());
}).on('close', function () {
    const [N, S, M] = input[0].split(' ').map(Number); // 곡의 개수 n 시작볼륨 s 최대볼륨 m
    const V = input[1].split(' ').map(Number);

    const dp = Array.from({length: N+1}, ()=> Array(M+1).fill(false));
    
    dp[0][S] = true;

    for(let i = 1; i <= N; i++){
        for(let j = 0; j <= M; j++){
            if(dp[i-1][j]){
                if(j+V[i-1] <= M) dp[i][j+V[i-1]] = true;
                if(j-V[i-1] >= 0) dp[i][j-V[i-1]] = true;
            }
        }
    }

    let maxVolume = -1;
    
    for(let j = 0; j <= M; j++){
        if(dp[N][j]) maxVolume = Math.max(maxVolume, j);
    }

    console.log(maxVolume);
});