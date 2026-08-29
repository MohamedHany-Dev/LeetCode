class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> vp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vp.emplace_back(nums[i], i);
        }
        sort(begin(vp), end(vp));
        for (int i = 0; i < n; i++) {
            int cur = i;
            // values -> indexes
            vector<int> idx{vp[cur].second};
            while (cur + 1 < n and vp[cur + 1].first - vp[cur].first <= limit) {
                idx.push_back(vp[cur + 1].second);
                ++cur;
            }
            // apply the sort be indexes which allow limit
            sort(begin(idx), end(idx));
            for (int j = 0, k = i; j < idx.size(); j++, k++) {
                nums[idx[j]] = vp[k].first;
            }
            i = cur;
        }
        return nums;
    }
};