const int N = 1e5 + 5;

int spf[N];
vector<int> factors[N];

void Mod_Sieve() {
    iota(begin(spf), end(spf), 0);

    for (int i = 2; i * i < N; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void mod_factorize(int n) {
    int m = n;

    while (n != 1) {
        int prime = spf[n];

        // Add each prime only once
        factors[m].push_back(prime);

        while (n % prime == 0) {
            n /= prime;
        }
    }
}

bool flag = false;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        if (!flag) {
            Mod_Sieve();
            flag = true;
        }

        vector<int> mp(N, 0);

        int l = 0;
        int longest = 0;
        int dis = 0;

        for (int r = 0; r < nums.size(); ++r) {

            // Generate prime factors if not already calculated
            if (factors[nums[r]].empty()) {
                mod_factorize(nums[r]);
            }

            // Add nums[r]
            for (int prime : factors[nums[r]]) {
                if (++mp[prime] == 1) {
                    ++dis;
                }
            }

            // Keep at most k distinct prime factors
            while (dis > k) {

                for (int prime : factors[nums[l]]) {
                    if (--mp[prime] == 0) {
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