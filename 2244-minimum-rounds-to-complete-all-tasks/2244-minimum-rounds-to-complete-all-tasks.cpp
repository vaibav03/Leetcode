class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> M;
        for(auto x : tasks){
            M[x]++;
        }
        long long ans{};
        for(auto x : M){
            if(x.second == 1) return -1;
            ans += (ceil(x.second / 3.0));
        }
        return ans;
    }
};