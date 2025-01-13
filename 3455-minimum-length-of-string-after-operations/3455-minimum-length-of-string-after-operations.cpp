class Solution {
public:
    int minimumLength(string s) {
       vector<int> freq(26);
       for(int i=0;i<s.size();i++){
        freq[s[i] - 'a']++;
       }
        int ans{};
       for(int i=0;i<26;i++){
        if(freq[i] && freq[i]%2)
        ans+=1;
        else if(freq[i] && !(freq[i]%2))
        ans+=2;
       }
       return ans;
    }
};