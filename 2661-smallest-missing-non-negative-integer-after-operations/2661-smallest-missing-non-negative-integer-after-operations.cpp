class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> M;
        for(int i=0;i<nums.size();i++){
            M[( nums[i]%value +value)%value]++;
        }
        int i = 0;
        while(M[i%value]--) i++;

        return i;
        }
};