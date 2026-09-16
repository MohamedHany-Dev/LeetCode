class Solution {
    int mod = 1e9 + 7;

    // Helper to calculate (base^exp) % mod
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    // Modular Inverse (Fermat's Little Theorem)
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }

public:
    int numberOfSets(int n, int k) {
        if (2 * k > n + k - 1) return 0;

        int total_points = n + k - 1;
        int points_to_pick = 2 * k;

        long long num = 1, den = 1;
        
        // Calculate (total_points)C(points_to_pick)
        for (int i = 0; i < points_to_pick; i++) {
            num = (num * (total_points - i)) % mod;
            den = (den * (i + 1)) % mod;
        }

        return (num * modInverse(den)) % mod;
    }
};

// math i didn't solve it