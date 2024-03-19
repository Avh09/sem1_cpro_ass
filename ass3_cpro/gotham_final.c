#include <stdio.h>

#define MOD 1000000007

int main() {
    int n,m,k,x,y;
    scanf("%d %d %d", &n, &m, &k);
    int dp[n + 1][m + 1];

    // Initialize a 2D array dp with all elements set to 0
    // int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<k;i++){
        scanf("%d %d",&x,&y);
        dp[x][y]=-1;
    }

    // Initialize the starting position
    for (int i=1;i<=m;i++)
    {
    dp[1][i] = 1;
    }

    // Define knight move offsets
    int dr[] = {2, 2, 1, 1};
    int dc[] = {-1, 1, -2, 2};

    // Loop through the grid and update dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(dp[i][j]==-1)continue;
            int c=dp[i][j];
            for (int move = 0; move < 4; move++) {
                int r = i + dr[move];
                int c = j + dc[move];
                if (r >= 1 && r <= n && c >= 1 && c <= m && dp[r][c]!=-1) {
                    dp[r][c] = (dp[i][j] + dp[r][c]) % MOD;
                }
            }
        }
    }

    // Calculate and print the total number of valid paths to each entrance
    for (int i = 1; i <= m; i++) {
        printf("%d ", dp[n][i]);
    }

    return 0;
}