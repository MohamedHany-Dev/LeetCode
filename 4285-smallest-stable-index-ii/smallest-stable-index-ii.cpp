class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> min_suff(n + 1, 1e9);
        for(int i = n - 1; i >= 0; i--) {
            min_suff[i] = min(min_suff[i + 1], nums[i]);
        }
        int max_pref = -1;
        for(int i = 0; i < n; i++) {
            max_pref = max(max_pref, nums[i]);
            if(max_pref - min_suff[i] <= k) 
                return i;
        }
        return -1;
    }
};