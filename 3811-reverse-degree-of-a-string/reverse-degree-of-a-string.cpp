class Solution {
public:
    int reverseDegree(string s) {
        int ans=  0;
        for(int i = 0; i < s.size(); i++) {
            int idx = i + 1;
            int rev = 26 - (s[i] - 'a');
            ans += idx * rev;
        }
        return ans;
    }
};