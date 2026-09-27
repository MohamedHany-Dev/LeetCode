class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            if(s[i] != ')') {
                st.push(s[i]);                        
            }else {
                string tmp = "";
                while(st.size() and st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                }
                st.pop();
                for(auto c: tmp) {
                    st.push(c);
                }
            }
        }
        string res = "";
        while(st.size()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};