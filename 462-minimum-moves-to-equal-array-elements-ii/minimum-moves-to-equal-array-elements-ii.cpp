class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // let's try every choice using the prefix & suffix
        long long pref = 0, minMoves = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum -= nums[i];
            long long before = 1LL * i * nums[i] - pref;
            long long after = sum - 1LL * (n - i - 1) * nums[i];
            minMoves = min(minMoves, before + after);
            pref += nums[i];
        }
        return minMoves;
    }
};