class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=1,j=0;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        while(i<intervals.size()){
        if(ans[j][1]<intervals[i][0]){
            ans.push_back({intervals[i][0],intervals[i][1]});
            j++;
            i++;
        }
        else
            {
            ans[j][1]=max(intervals[i][1],ans[j][1]);
            i++;
        }
        }
        return ans;
    }
};