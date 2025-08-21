class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
     unordered_set<int> ans,curr,prev;
     for(int num : arr){
        curr.clear();
        curr.insert(num);
        for(int sub : prev){
            curr.insert(sub | num);
        }
        prev = curr;
        ans.insert(curr.begin(),curr.end());
     }
     return ans.size();
    }
};