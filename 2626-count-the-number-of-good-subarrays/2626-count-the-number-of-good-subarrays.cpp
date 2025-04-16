class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
    int left = 0,right =-1 , pres_pair{};
    long long ans{};
    map<long long ,long long > M;
    for( left=0;left<nums.size();left++){
        while(pres_pair<k && right+1<nums.size()){
            M[nums[right+1]]++;
            pres_pair+=(M[nums[right+1]]-1);
            right++;
        }
        
        if(pres_pair>=k)
        ans+=(nums.size()-right);

        // cout<<pres_pair<<" "<<left<<" "<<right<<" "<<ans<<endl; 
        pres_pair-=(M[nums[left]]-1);
        M[nums[left]]--;
    }
    return ans;
    }
};