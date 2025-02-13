class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        string ans = "";
        st.push(s[0]);
        int  i = 1;
        while(i<s.size()){
            if(s[i]>='0' && s[i]<='9' ){
                char close = st.top();
                if( !( close>='0'&& close<='9') && !st.empty() )
                {
                    st.pop();
                } else{
                    st.push(s[i]);
                }
            } else{
                st.push(s[i]);
            }
          i++;
        }

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};