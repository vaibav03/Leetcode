class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxe {},ans;
        for(int i=0;i<values.size();i++){
            if(i)
            ans = max( ans,values[i] - i + maxe );

            maxe = max(maxe,values[i]+i);
        }
        return ans;
    }
};