class Solution {
public:
    bool compare(string s1,string s2){
        int i{},j{},inc{};
        if(s1.size() - s2.size() != 1) return false;
        while(i<s1.size() && j<s2.size()){
            if(s1[i]==s2[j]){
            i++;
            j++;
            }else{
                inc++;
                i++;
            }
        }
        return (inc<=1) ? true : false;
    }
    static bool cmp(string s1,string s2){
        return s1.size()<s2.size() ; 
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            cout<<words[i]<<" ";
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j])==1 && dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        cout<<endl;
        return *max_element(dp.begin(),dp.end());
    }
};