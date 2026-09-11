class Solution {
public:
    int freq[10];
    int rec(int i, int gen) {
        int ret = 0;
        if (i == 3) {
            return gen % 2 == 0 ? 1 : 0;
        }
        for (int d = gen == 0 ? 1 : 0; d <= 9; d++) {
            if (freq[d] > 0) {
                --freq[d];
                ret += rec(i + 1, gen * 10 + d);
                ++freq[d];
            }
        }
        return ret;
    }
    int totalNumbers(vector<int>& digits) {
        int has_even = 0;
        for (auto x : digits) {
            ++freq[x];
            has_even |= !(x & 1);
        }
        if (!has_even)
            return 0;
        return rec(0, 0);
    }
};