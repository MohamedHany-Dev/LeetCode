class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int m = queries.size();
        vector<long long> ans(m), pref(n + 1); // ans : one based
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        for (int i = 0; i < m; i++) {
            auto idx =
                upper_bound(begin(nums), end(nums), queries[i]) - begin(nums);
            int a = idx, b = n - idx;
            long long after = (pref[n] - pref[idx]) - 1LL * b * queries[i];
            long long before = 1LL * a * queries[i] - pref[idx];
            ans[i] = before + after;
        }
        return ans;
    }
};