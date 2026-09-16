class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {

        vector<vector<int>> dp(
            n,
            vector<int>(k + 1, 0)
        );

        // Selecting 0 segments: 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {

            long long prefixSum = 0;

            for (int i = 1; i < n; i++) {

                // Add ways to start a new segment
                prefixSum = (
                    prefixSum + dp[i - 1][j - 1]
                ) % MOD;

                // Skip current point OR
                // add a segment ending at current point
                dp[i][j] = (
                    dp[i - 1][j] + prefixSum
                ) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};

// it like coins 2 problem , i can got it also