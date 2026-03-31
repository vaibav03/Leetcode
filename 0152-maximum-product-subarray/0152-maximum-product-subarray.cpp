class Solution {
public:
int findAns(vector<int> &nums){
    if(nums.empty()) return INT_MIN;

    if(nums.size() == 1) return nums[0];

        int neg{},ans = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0) neg++;
        }
        if(neg%2 == 0){
            for(auto x : nums) {
                ans*=x;
            }
            return ans;
        }else{
            int maxi1 = 1,maxi2 = 1;
            int dupe = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<0) dupe++;
                if(dupe == neg) break;
                maxi1*=nums[i];
            }
            dupe = 0;
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i]<0) dupe++;
                if(dupe == neg ) break;
                maxi2*=nums[i];
            }
            cout<<maxi1<<" "<<maxi2<<endl;
            return max(maxi1,maxi2);
} }

    int maxProduct(vector<int>& nums) {
        vector<int> curr;
        int ans = INT_MIN;
        for(auto x : nums){
            if(x == 0){
                ans = max({ans , findAns(curr),0});
                curr.clear();
            }else{
            curr.push_back(x);
            }
        }
        ans = max(ans ,findAns(curr));
        return ans;
    }
    
};