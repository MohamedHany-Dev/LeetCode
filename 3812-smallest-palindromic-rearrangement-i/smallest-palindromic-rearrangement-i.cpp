class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26);
        for (auto c : s) {
            ++freq[c - 'a'];
        }
        int mid = -1;
        int n = s.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (freq[i] == 1) {
                    s[n / 2] = char(i + 'a');
                    --freq[i];
                } else {
                    s[l++] = s[r--] = char(i + 'a');
                    freq[i] -= 2;
                }
            }
        }
        return s;
    }
};