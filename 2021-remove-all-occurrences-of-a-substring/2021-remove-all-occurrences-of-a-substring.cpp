class Solution {
public:
    bool isMatch(stack<char> st, string part) {
        string res = "";
        for (int i = 0; i < part.size(); i++) {
            if (!st.empty()) {
                char s = st.top();
                st.pop();
                res += s;
            }
        }
        reverse(res.begin(),res.end());
        return (res == part);
    }
    string removeOccurrences(string s, string part) {
        int i = 0;
        stack<char> st;
        while (i < s.size()) {
            st.push(s[i]);
            if (isMatch(st, part)) {
                for (int j = 0; j < part.size(); j++) {
                        st.pop();
                }
            }
        i++;
        }
        string ans = "";
        while (!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};