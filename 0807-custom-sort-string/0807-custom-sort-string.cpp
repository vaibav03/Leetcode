class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> M;
        string ans = "";
        for(auto x : s){
            M[x]++;
        }
        for(auto x : order){
            if(M.count(x)){
                while(M[x]--) ans+=x;

                M.erase(x);
            }
        }
        cout<<ans<<endl;
        for(auto x : M){
            while(x.second--) ans+=x.first;

               // M.erase(x);
        }
        
    return ans;
    }
};