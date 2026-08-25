class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> vis(201);
        for(auto x: nums) {
            vis[x] = true;
        }
        int cur = k;
        while(vis[cur]) {
            cur += k;
        }
        return cur;
    }
};