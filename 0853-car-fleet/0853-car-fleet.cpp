class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pv;
        for(int i=0;i<position.size();i++){
            pv.push_back({position[i],speed[i]});
        }
        sort(pv.begin(),pv.end());
        float time = (target - pv.back().first )/ (float) pv.back().second ;
        float tar = target;
        int ans = 1;
        for(int i=pv.size() - 1;i>=0;i--){
           cout<<pv[i].first + time*pv[i].second <<" "<<i<<endl;

            if(pv[i].first + time*pv[i].second >= tar) continue;
            else {
                time = (target - pv[i].first )/ (float) pv[i].second;
                tar = pv[i].first + time*1.00*pv[i].second;
                ans++;
            }
        }
        return ans;
    }
};