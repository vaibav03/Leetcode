class Solution {
public:
    int maxDifference(string s) {
        map<int,int> M;

        for(int i=0;i<s.size();i++){
            M[s[i]-'a']++;
        }

        int minE = INT_MAX,maxO{};
        for(auto x : M){
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second%2==0) minE = min(minE,x.second);
            else maxO = max(maxO,x.second);
        }

        return (minE!=INT_MAX)? maxO - minE : maxO;
    }
};