class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int>  op(nums.size(),0);
        int flips{},operations;
        for(int i=0;i<=nums.size()-k;i++){
            if(i>=k) operations = flips - op[i-k];
            else  operations = flips;

            if( (nums[i] == 0 && operations%2 == 0) || (nums[i]==1 && operations%2 ==1) ){
                flips++;
            }
            op[i] = flips;
        }
        for(int i=0;i<nums.size();i++) {
            cout<<op[i]<<" ";
        }
        cout<<endl;
        bool notpos = false;
        
        for(int i=nums.size() - k+1; i<nums.size();i++){
            if(i>=k) operations = flips - op[i-k];
            else  operations = flips;
            if( ((nums[i] == 0 && operations%2 == 0) || (nums[i]==1 && operations%2 == 1) )){
                return -1;
            }
        }
        return flips;    
    }
};