class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mpp;
        vector<int> ans,dupe = arr;
        sort(arr.begin(),arr.end());
        int curr=1;
        for(auto x : arr){
            if(mpp.find(x) == mpp.end()){ mpp[x] = curr++; }
        }
        for(auto x : dupe){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};