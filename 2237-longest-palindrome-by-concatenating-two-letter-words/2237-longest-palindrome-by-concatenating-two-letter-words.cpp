class Solution {
public:
    bool isPalindrome(string s){
        for(int i =0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i]) return false;
        }
        return true;
    }
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> M;
        int ans{},pal{};
        for(int i=0;i<words.size();i++){
                M[words[i]]++;
        }

        for(auto x : M){
            string rev = x.first;
            reverse(rev.begin(),rev.end());
            cout<<x.first<<" "<<x.second<<endl;
            if(rev==x.first){
                ans+=(4*(x.second/2));
                if(x.second%2) pal=1;
            }

            if(rev!=x.first && M.find(rev)!=M.end() ){
            int pairs = min(x.second, M[rev]);
            ans += 4 * pairs;
            M[rev] = 0; 
            M[x.first] = 0;
            }
        }

        if(pal) ans+=2; 
        return ans;
    }
};