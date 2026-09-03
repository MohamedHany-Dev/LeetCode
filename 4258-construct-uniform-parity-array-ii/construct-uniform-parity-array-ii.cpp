class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, mn = INT_MAX;
        for(auto x: nums1) {
            odd |= x & 1;
            mn = min(mn, x);
        }
        if(mn & 1) return true;

        return !odd;
    }
};