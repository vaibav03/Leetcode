class Solution {
public:
    int low_b(vector<int> &nums,int val){
        int ans = nums.size()-1, l = 0,hi = nums.size()-1;
        while(l  <= hi){
            int mid = (l+hi)/2;
            if(nums[mid] <  val) l = mid+1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<long long> ans;
        vector<long long> pre(n ,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        for(auto q : queries){
            int lb = low_b(nums, q);
            cout<<lb<<" "<<q<<endl;
            long long curr;
            if(lb != 0)
             curr = abs(pre[lb-1] - (lb)*1ll*q) + abs(pre[n-1] - pre[lb-1] - (n-lb)*1ll*q);
            else
            curr = abs(pre[n-1] - n*1ll*q);
            ans.push_back(curr);
        }
        return ans;
    }
};


