class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = accumulate(derived.begin(),derived.end(),0), len = derived.size();
        if(derived[len-1]==1) sum--;
        
        if( (sum%2==0 && derived[len-1]==1) || (sum%2 && derived[len-1]==0)) {
            return false;
        }
        return true;
    }
};