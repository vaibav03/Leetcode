class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans;
        int pre{};
        map<int,int> hash,diff;
        for(int i=0;i<flowers.size();i++){
            hash[flowers[i][0]] += 1 ;
            hash[flowers[i][1]+1] += -1; 
        }
        for(auto x : hash){
            //cout<<x.first<<" "<<x.second<<endl;
            pre+=x.second;
            diff[x.first] = pre;
        }
        for(int i=0;i<people.size();i++){
            auto lb = diff.lower_bound(people[i]);
            if(lb!=diff.begin() && lb->first != people[i])
            lb = prev(lb);
            else if(lb == diff.begin() && lb->first!=people[i]){ ans.push_back(0); continue; }

            ans.push_back(lb->second);
        }
        return ans;
    }
};