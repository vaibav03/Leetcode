class Solution {
public:
int sumofdigits(int n){
    int ans{};
    while(n){
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> M;
        for(int i=0;i<nums.size();i++){
         int sum  = sumofdigits(nums[i]);
         if(M[sum].size()==2){
            if(nums[i] > min(M[sum][0],M[sum][1])){
                if(M[sum][0] == min(M[sum][0],M[sum][1]) ){
                    M[sum][0] = nums[i];
                } else{
                    M[sum][1] = nums[i];
                }
            }
         } else if(M[sum].size()<2) {
            M[sum].push_back(nums[i]);
         }
        }

        int ans=-1;
        for(auto i:M){
            if(i.second.size()==2)
            ans = max(i.second[0]+i.second[1],ans);
        }
        return ans;
    }
};