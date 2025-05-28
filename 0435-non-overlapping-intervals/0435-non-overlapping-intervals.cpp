class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
         return (a[1]<b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int ans{};
        int l{}, r=1;

        while(r<intervals.size() && l<intervals.size() && l<r){
            if(intervals[l][1]>intervals[r][0]){
                ans++;
                r++;
            }else{
                l=r;
                r++;
            }
        }
        return ans;
    }
};