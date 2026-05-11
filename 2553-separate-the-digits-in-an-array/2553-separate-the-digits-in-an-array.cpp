class Solution {
public:
    vector<int> ans;
    void getDigits(int num){
        vector<int> curr;
        while(num){
            curr.push_back(num%10);
            num/=10;
        }
        for(int i=curr.size()-1;i>=0;i--){
            ans.push_back(curr[i]);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for(auto num : nums){
            getDigits(num);
        }
        return ans;
    }   
};