class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); //Fixing ths median element
        int mid = nums[n / 2];
        int moves = 0;
        for(auto x: nums) {
            moves += abs(x - mid);
        }
        return moves;
    }
};