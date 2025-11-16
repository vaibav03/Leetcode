class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> hash;
        int i {},j{}, maxFreq{},ans{};

        while(j<s.size()){
            cout<<i<<' '<<j<<endl;
            hash[s[j]]++;
            maxFreq = max(hash[s[j]], maxFreq);

            if(j-i+1 - maxFreq > k){
                hash[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};