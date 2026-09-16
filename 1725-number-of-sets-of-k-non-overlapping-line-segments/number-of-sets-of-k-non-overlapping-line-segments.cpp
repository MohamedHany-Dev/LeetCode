class Solution {
    int dp[1000][1000][2];
    int mod = 1e9 + 7;

    int rec(int i, int k, int is_drawing, int n) {
        if (k == 0) return 1; // Successfully formed k segments
        if (i == n) return 0; // Reached the end without forming k segments

        if (dp[i][k][is_drawing] != -1) return dp[i][k][is_drawing];

        long long res = 0;

        if (is_drawing) {
            // Option 1: Continue drawing the current segment to the next point
            res = (res + rec(i + 1, k, 1, n)) % mod;
            // Option 2: Stop drawing at this point (completes 1 segment)
            // Note: We stay at point 'i' because segments can share endpoints
            res = (res + rec(i, k - 1, 0, n)) % mod;
        } else {
            // Option 1: Skip this point, don't start a segment here
            res = (res + rec(i + 1, k, 0, n)) % mod;
            // Option 2: Start a new segment from this point
            res = (res + rec(i + 1, k, 1, n)) % mod;
        }

        return dp[i][k][is_drawing] = res;
    }

public:
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        // Start at point 0, need k segments, currently not drawing
        return rec(0, k, 0, n); 
    }
};