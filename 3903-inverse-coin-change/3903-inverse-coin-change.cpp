class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = numWays.size();
        vector<int> coins,ways_prev(n+1,0);
        ways_prev[0] = 1;
        for(int i=0;i<n;i++){
            int x = numWays[i] - ways_prev[i+1];
            if(x>1 || x<0 ) return {};
            if(x==0) continue;

            coins.push_back(i+1);
            for(int j=i+1;j<=n;j++){
                ways_prev[j] += ways_prev[j-(i+1)];
            }
        }
    return coins;
    }
};