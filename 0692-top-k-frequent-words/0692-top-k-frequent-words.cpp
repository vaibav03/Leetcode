class Solution {
public:
    struct cmp{
    bool operator()(pair<int,string> &a,pair<int,string> &b) const {
        if (a.first != b.first) return a.first < b.first;

            return a.second > b.second;
    }
};

    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> M;
        for(int i=0;i<words.size();i++){
            M[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto x: M){
            pq.push({x.second,x.first});
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};