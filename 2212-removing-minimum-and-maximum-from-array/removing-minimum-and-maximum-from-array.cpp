class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = 0, mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[mx]) mx = i;
            if(nums[i] < nums[mn]) mn = i; 
        }
        int l = min(mn, mx);
        int r = max(mn, mx);
        int deletion = min(r + 1, n - l); // remove from [left | right] only
        deletion = min(deletion, n - (r - l - 1));
        return deletion;
    }
};