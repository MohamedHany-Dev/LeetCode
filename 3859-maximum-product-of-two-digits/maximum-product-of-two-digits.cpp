class Solution {
public:
    int maxProduct(int n) {
        int maxd1 = 0, maxd2 = 0;
        while(n > 0) {
            int d = n % 10;
            if(d > maxd1) {
                maxd2 = maxd1;
                maxd1 = d;
            } else if(d > maxd2) {
                maxd2 = d;
            }
            n /= 10;
        }
        return maxd1 * maxd2;
    }
};