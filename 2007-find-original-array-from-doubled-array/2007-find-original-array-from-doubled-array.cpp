class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> hash;
        for(auto x : changed){
            hash[x]++;
        }
        vector<int> ans;
        if(hash[0] %2 != 0)  return {};

        hash[0]/=2;
        while(hash[0]>0 && hash[0]--){
            ans.push_back(0);
        }
        

        for(auto x : hash){
            int val = x.first;
            auto it = hash.find(val*2);

            int cnt = x.second;
            if(cnt == 0 && it == hash.end()) continue;
            else if(it == hash.end()) return {};
            while(cnt-- >0){
                ans.push_back(val);
                it->second--;
            }
        }
        return ans;

    }
};