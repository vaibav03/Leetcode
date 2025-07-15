class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap;

        gap.push_back(startTime[0]);
        for(int i=0;i<startTime.size()-1;i++){
             gap.push_back( startTime[i+1] - endTime[i]);
        }
        gap.push_back(eventTime - endTime[endTime.size()-1]);

        for(int i=0;i<gap.size();i++){
            cout<<gap[i]<<" ";
        }
        cout<<endl;
        int wind{},ans{};
        for(int i=0;i<=k;i++){
            wind+=gap[i];
        }

        for(int i=k+1;i<gap.size();i++){
            ans = max(ans,wind);
            wind-=gap[i-k-1];
            wind+=gap[i];
        }

        ans = max(ans,wind);
        return ans;
    }
};