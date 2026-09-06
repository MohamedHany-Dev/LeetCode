class Solution {
public:
    int dp[1000][1000];
    int rec(int i, int j, string& s, string& t) {
        if (j == t.size())
            return 1; // valid
        if (i == s.size())
            return 0; // invalid

        int& ret = dp[i][j];
        if (~ret)
            return ret;

        ret = 0;
        ret += rec(i + 1, j, s, t);

        if (s[i] == t[j]) {
            ret += rec(i + 1, j + 1, s, t);
        }
        return ret;
    }
    int numDistinct(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < t.size(); j++) {
                dp[i][j] = -1; // reset
            }
        }
        return rec(0, 0, s, t);
    }
};