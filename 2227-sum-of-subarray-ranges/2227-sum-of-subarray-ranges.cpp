class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        int n = nums.size();
        vector<long long> rmax(n,n),rmin(n,n),lmax(n,-1),lmin(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty())
            lmax[i] = st.top();
            
            st.push(i);
        }
       while(!st.empty()){st.pop();}
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty())
            lmin[i] = st.top();

            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(!st.empty())
            rmax[i] = st.top();
            
            st.push(i);
        }
        while(!st.empty()){st.pop();}

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(!st.empty())
            rmin[i] = st.top();
            
            st.push(i);
        }
        long long sum{};
        for(int i=0;i<n;i++)
        {
            long long leftMin=i-lmin[i],rightMin=rmin[i]-i;
            long long leftMax=i-lmax[i],rightMax=rmax[i]-i;
            sum+=(leftMax*rightMax-leftMin*rightMin)*nums[i];
        }
        return sum;
    }

};
