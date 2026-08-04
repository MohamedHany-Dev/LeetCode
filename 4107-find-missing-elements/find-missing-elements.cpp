class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<bool> freq(mx + 1);
        for (int i = 0; i < n; i++) {
            freq[nums[i]] = true;
        }
        vector<int> rem;
        for (int i = mn + 1; i < mx; i++) {
            if (!freq[i]) {
                rem.push_back(i);
            }
        }
        return rem;
    }
};