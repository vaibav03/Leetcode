class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int> M;
        for(int i=0;i<nums.size();i++){
            M[nums[i]]++;
        }

        for(auto x : M){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        // while(!pq.empty()){
        //     cout<<pq.top().first
        // }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};