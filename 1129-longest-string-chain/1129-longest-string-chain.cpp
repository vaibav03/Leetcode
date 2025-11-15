class Solution {
public:
    bool comp(string a,  string b){
        if(b.size() - a.size() != 1 ) return false;
        int i{},j{},differ{};
        while( i < a.size() && j < b.size() ){
            if(a[i]!=b[j]){
                differ++;
                j++;
            }else {
                i++;
                j++;
            }
        }
        return (j == b.size() - 1 || differ ==1 ); 
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(comp(words[j],words[i])) dp[i] = max(dp[j]+1,dp[i]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};