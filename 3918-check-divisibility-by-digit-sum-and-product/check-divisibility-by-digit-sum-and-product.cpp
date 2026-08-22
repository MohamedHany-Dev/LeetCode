class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1, sum = 0;
        int m = n;
        while(m > 0) {
            sum += m % 10;
            prod *= m % 10;
            m /= 10;
        }
        return n % (sum + prod) ? false : true;
    }
};