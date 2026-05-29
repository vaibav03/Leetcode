class Solution {
public:
    int val(int n){
        int ans{};
        while(n){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(auto num : nums){
            ans = min(ans, val(num));
        }
        return ans;
    }
};