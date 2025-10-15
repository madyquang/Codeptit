#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= 9; i++) dp[1][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int l = 0; l <= 9; l++) {
                for (int j = l; j <= k; j++) {
                    dp[i][j] = (dp[i][j] % MOD + dp[i - 1][j - l] % MOD) % MOD;
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}