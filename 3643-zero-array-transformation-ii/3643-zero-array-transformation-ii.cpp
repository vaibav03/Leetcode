class Solution {
public:
    bool isZeroArray(vector<int> nums, vector<vector<int>> queries, int ind){
        vector<int> diff(nums.size()+1,0);

        for(int i=0;i<=ind;i++){
            diff[queries[i][0]]+=(queries[i][2]);
            diff[queries[i][1]+1]-=(queries[i][2]);
        }
        if(ind ==0 ){
            for(int i=0;i<diff.size();i++){
                cout<<diff[i]<<" "; 
            }
            cout<<endl;
        }
        nums[0]-=diff[0];
        if(nums[0]>0) return false; 
        for(int i=1;i<nums.size();i++){
            diff[i] += diff[i-1];
            nums[i]-=diff[i];
            if(nums[i]>0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,r=queries.size()-1;
        if(isZeroArray(nums,queries,-1)) return 0;
        
        while(l<r){
            int mid = (l+r)/2;
            if(isZeroArray(nums,queries,mid)){
                r=mid;
            }else {
                l=mid+1;
            }
        }
         cout<<isZeroArray(nums,queries,0)<<endl;
        return (isZeroArray(nums,queries,(l+r)/2) ) ? (l+r)/2 + 1 : -1;
    }
};