class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> last(26, n + 1), first(26, -1);
        for(int i = 0; i < n; i++) {
            char c = word[i];
            if(islower(c)) {
                last[c - 'a'] = i;
            } else if(first[c - 'A'] == -1){
                first[c - 'A'] = i;
            }
        }
        int cnt = 0;
        for(int c = 'a'; c <= 'z'; c++) {
            if(last[c - 'a'] < first[c - 'a']) ++cnt;
        }
        return cnt;
    }
};