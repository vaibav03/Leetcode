class Solution {
public:
    int rec(vector<int> &nums1, vector<int>& nums2, int i,int j,bool chosen, vector<vector<vector<int>>>& dp){
        //cout<<i<<" "<<j<<" "<<chosen<<endl;
        if(i == nums1.size() || j == nums2.size()){
            if(chosen == false) return -1e9;
            else return 0;
        }

        if(dp[i][j][chosen] != -1) return dp[i][j][chosen];
        
        return dp[i][j][chosen] = max({
            rec(nums1,nums2,i+1,j,chosen,dp),
            rec(nums1,nums2,i,j+1,chosen,dp),
           nums1[i]*nums2[j] + rec(nums1,nums2,i+1,j+1,true,dp)
        });

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return rec(nums1,nums2,0,0,false,dp);
    }
};