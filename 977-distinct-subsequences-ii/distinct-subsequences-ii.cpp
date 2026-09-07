const int mod = 1e9 + 7;
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n + 1), last(26, -1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] * 2 % mod; // when add new char combination increase double 
            if(last[s[i]- 'a'] >= 0) {
                dp[i + 1] -= dp[last[s[i]- 'a']]; // when replace cur with last appearance (mean make cur last) 
            }
            if(dp[i + 1] < 0) dp[i + 1] += mod;
            last[s[i] - 'a'] = i;
        }
        --dp[n];
        if(dp[n] < 0) dp[n] += mod;
        return dp[n];
    }
};