class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> freq(2 * n + 2), pref(2 * n + 2);
        freq[n + 1] = pref[n + 1] = 1;
        int sum = n + 1;
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            nums[i] == target ? ++sum : --sum;
            ans += pref[sum - 1]; // take the sum of smaller than currrent index
            // update the result
            ++freq[sum];
            pref[sum] = pref[sum - 1] + freq[sum];
        }
        return ans;
    }
};

// video : https://www.youtube.com/watch?v=YoHRXgCiS5E