class Solution {
public:

    int longestIdealString(string s, int k) {
        int n = s.size();
        unordered_map <int,int> M;

        for(int i=0;i<n;i++){
            int maxi{};
            for(int j=0;j<=k;j++){
                int keyf = s[i]+j-'a',keyb = s[i] - j - 'a';
                if(M.find(keyf)!=M.end()){
                    maxi = max(maxi, M[keyf]);
                }
                if(M.find(keyb)!=M.end()){
                    maxi = max(maxi, M[keyb]);
                }
            }
            M[s[i] - 'a'] = maxi +1;
        }
        int ans{};
        for(auto ele : M){
            ans = max(ans,ele.second);
        }
        return ans;
    }
};