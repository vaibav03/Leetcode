class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int i = 2*n-1;
        stack<int> st;
        vector<int> ans(n,-1);
        while(i>=0){
            int ind  = i%n;
            while( !st.empty() && nums[ind]>=st.top()){
                st.pop();
            }
            if(i<n && !st.empty())
            ans[i] = st.top();

            st.push(nums[ind]);
            i--;
        }
        return ans;
    }
};