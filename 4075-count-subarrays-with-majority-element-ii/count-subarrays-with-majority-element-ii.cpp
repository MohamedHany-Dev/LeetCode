using ll = long long;

const int N = 200005;

struct FenwickTree {
    ll bit[N] = {};

    void add(int idx, ll val) {
        while (idx < N) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll query(int idx) {
        ll ret = 0;
        while (idx > 0) {
            ret += bit[idx];
            idx -= idx & -idx;
        }
        return ret;
    }

    ll prefix(int l, int r) {
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        FenwickTree ft;

        int offset = n + 1;
        int sum = 0;

        ll ans = 0;

        // Insert empty prefix sum = 0
        ft.add(offset, 1);

        for (int x : nums) {
            if (x == target)
                sum++;
            else
                sum--;

            int idx = sum + offset;

            // Count previous prefix sums < current sum
            ans += ft.query(idx - 1);

            // Insert current prefix sum
            ft.add(idx, 1);
        }

        return ans;
    }
};

// video : https://www.youtube.com/watch?v=YoHRXgCiS5E