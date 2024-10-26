class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> M;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])
             {
              st.pop();
             }
             if(st.empty())
             M[nums2[i]] = -1;
             else
             M[nums2[i]] = st.top();

             st.push(nums2[i]);
        }
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
         if(M[nums1[i]]==0)
         v.push_back(-1);
         else
         v.push_back(M[nums1[i]]);
        } 
        return v;
    }
};