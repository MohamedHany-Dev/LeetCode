const int N = 1e5 + 5;
int spf[N];
vector<int> factors[N];
// time n * log(n)
void get_factors() {
    for (int i = 2; i < N; ++i) {
        if (factors[i].empty()) { // i is prime
            for (int j = i; j < N; j += i) {
                factors[j].push_back(i);
            }
        }
    }
}
bool flag = false;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        if (!flag) {
            get_factors();
            flag = true;
        }
        int dis = 0;
        vector<int> mp(N);
        int l = 0, longest = 0;
        int n = nums.size();
        for (int r = 0; r < n; ++r) {
            // add primes of new element
            for (auto x : factors[nums[r]]) {
                if(++mp[x] == 1) ++dis;
            }
            // remove from l if distinct more than k
            while (dis > k) {
                // remove primes of left element
                for (auto x : factors[nums[l]]) {
                    if (--mp[x] == 0) {
                        --dis;
                    }
                }
                ++l;
            }
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};