class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int maxPref=0,minPref = 0,pref{};
        for(int i = 0;i<differences.size();i++){
            pref+=differences[i];
            maxPref = max(pref,maxPref);
            minPref = min(pref,minPref);
        }
        int diff{};
        if(maxPref!=INT_MIN && maxPref!=minPref)
        diff+=maxPref;
        if(minPref!=INT_MAX)
        diff-=minPref;

        cout<<minPref<<" "<<maxPref<<" "<<diff<<endl;
        return (upper- lower - diff+1>=0) ? upper- lower - diff+1 : 0 ;
    }
};