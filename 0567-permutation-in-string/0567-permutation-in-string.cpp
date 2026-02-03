class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0), freq2(26,0);
        for(auto x : s1){
            freq1[x-'a']++;
        }
        int i =0,j=0;
        while(j<s2.size()){
            if(j-i+1 > s1.size()){
                freq2[s2[i]-'a']--;
                i++;
            }

            freq2[s2[j]-'a']++;
            j++;
            if(freq1 == freq2) return true; 
        }
        return false;
       
    }
};