class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        stack<int> st;
        st.push(nums.size() - 1);
        for(int i=nums.size() - 2;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i] ) st.pop();

            if(!st.empty()){ cout<<i<<" "<<st.top()<<endl; ans[i] = nums[st.top()];}

            st.push(i);
        }   
        for(int i=nums.size() - 1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i] ) st.pop();

            if(!st.empty() && ans[i]==-1){ cout<<i<<" "<<st.top()<<endl; ans[i] = nums[st.top()];}

            st.push(i);
        }
        return ans;
    }
};