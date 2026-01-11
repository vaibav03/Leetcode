class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> prev(n), next(n);
        st.push(-1);
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 && heights[st.top()] >= heights[i]) st.pop();

            prev[i] = st.top();
            st.push(i);
        }
     
        while(!st.empty()) st.pop();

        st.push(heights.size());
        for(int i = heights.size() - 1;i>=0;i--){
            while(st.top()!=heights.size() && heights[st.top()] >= heights[i]) st.pop();

            next[i] = st.top();
            st.push(i);
            int curr = (next[i] - prev[i] - 1)*(heights[i]);
            ans = max(ans, curr);
        }

        return ans;
    }
};