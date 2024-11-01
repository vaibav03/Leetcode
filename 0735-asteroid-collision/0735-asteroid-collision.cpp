class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > 0) {
                st.push(arr[i]);
            } else {
                int push = 1;
                while (!st.empty() && st.top() > 0 && abs(arr[i]) >= st.top()) {
                    if (st.top() == abs(arr[i])) {
                        push = 0; 
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if (push && (st.empty() || st.top() < 0)) {
                    st.push(arr[i]);
                }
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  
        return ans;
    }
};
