class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> vis;
        for(auto num: arr1) {
            int x = num;
            while(x > 0) {
                vis[x] = true;
                x /= 10;
            }
        }
        int longest = 0;
        for(auto num: arr2) {
            int x = num;
            while(x > 0) {
                if(vis.find(x) != vis.end()) {
                    longest = max(longest, int(log10(x) + 1));
                }
                x /= 10;
            }
        }
        return longest;
    }
};