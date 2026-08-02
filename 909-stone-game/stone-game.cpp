class Solution {
public:
    int rec(int l, int r, vector<int>& piles, vector<vector<int>>& dp) {
        if(l > r) return 0;

        int &ret = dp[l][r];
        if(~ret)
            return ret;
            
        int left = piles[l] - rec(l + 1, r, piles, dp);
        int right = piles[r] - rec(l, r - 1, piles, dp);

        return ret = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(0, n - 1, piles, dp);
    }
};