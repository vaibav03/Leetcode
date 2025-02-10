class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        vector<int> pre(nums.size(),0);
        unordered_map<int,int> M;
        long long int ans{};
        pre[0] = nums[0];
        M[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            pre[i] = pre[i-1]^nums[i];
            M[pre[i]]++;
        }
        for(auto i : M){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i : M){
            if(i.first==0){
                ans+=(1ll*(i.second)*(i.second+1)/2);
                i.second=0;
            }
            int num = i.second;
            ans+=(1ll*(num)*(num-1)/2);
            i.second = 0;
        }
    return ans;
    }
};