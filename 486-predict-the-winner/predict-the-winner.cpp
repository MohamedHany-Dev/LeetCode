class Solution {
public:
    int all = 0;
    bool win = false;
    int rec(int l, int r,vector<int>& nums) {
        if(l > r) {
            return 0;
        }
        int left = nums[l] - rec(l + 1, r, nums);
        int right = nums[r] - rec(l, r - 1, nums);

        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) { 
        int n = nums.size();
        return rec(0, n - 1, nums) >= 0;
    }
};