class Solution {
public:
int waviness(int num){
    vector<int> nums;
    while(num){
        nums.push_back(num%10);
        num/=10;
    }
    int ans{};
    for(int i=1;i<nums.size() - 1;i++){
        if(nums[i] < nums[i-1] && nums[i]<nums[i+1]) ans++;
        else if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) ans++;
    }
    return ans;
}
    int totalWaviness(int num1, int num2) {
        int ans{};
        for(int i=num1;i<=num2;i++){
            ans+=waviness(i);
        }
        return ans;
    }
};