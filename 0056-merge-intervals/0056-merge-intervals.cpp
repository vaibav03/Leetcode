class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int last = intervals[0][1],start = intervals[0][0];
        for(int i=0;i<intervals.size();i++){
            if(last < intervals[i][0]){
                ans.push_back({start,last});
                start = intervals[i][0];
                last = intervals[i][1];
            }else{
                last = max(last,intervals[i][1]);
            }
        }
        ans.push_back({start,last});
        return ans;
    }
};