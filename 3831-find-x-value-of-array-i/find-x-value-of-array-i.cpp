class Solution {
public:
    long long dp[100001][5][3];

    int n, K, target;
    vector<int> a;

    long long rec(int i, int rem, int state) {
        if (i == n) {
            // We must have selected at least one element.
            // state == 0 means we never started.
            return state != 0 && rem == target;
        }

        long long &ret = dp[i][rem][state];

        if (~ret)
            return ret;

        ret = 0;

        if (state == 0) {
            // 1. Don't start the subarray yet
            ret += rec(i + 1, rem, 0);

            // 2. Start subarray from nums[i]
            int newRem = numsMod(i);

            ret += rec(i + 1, newRem, 1);
        }

        else if (state == 1) {
            // 1. Continue taking nums[i]
            int newRem = (1LL * rem * numsMod(i)) % K;

            ret += rec(i + 1, newRem, 1);

            // 2. End the subarray before nums[i]
            ret += rec(i + 1, rem, 2);
        }

        else {
            // state == 2
            // Subarray already ended.
            // We cannot take any more elements.
            ret += rec(i + 1, rem, 2);
        }

        return ret;
    }

    int numsMod(int i) {
        return a[i] % K;
    }

    vector<long long> resultArray(vector<int>& nums, int k) {
        a = nums;
        n = nums.size();
        K = k;

        vector<long long> ans(k);

        for (target = 0; target < k; target++) {
            memset(dp, -1, sizeof(dp));

            // rem doesn't matter before we've started,
            // so we can initialize it with 1 % k.
            ans[target] = rec(0, 1 % k, 0);
        }

        return ans;
    }
};