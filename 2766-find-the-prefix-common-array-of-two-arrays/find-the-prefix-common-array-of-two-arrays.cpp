class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int sum = 0;
        vector<int> freq(n + 1), C(n);
        for(int i = 0; i < n; i++) {
            if(++freq[A[i]] == 2) ++sum;
            if(++freq[B[i]] == 2) ++sum;
            C[i] = sum;
        }
        return C;
    }
};