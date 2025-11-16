class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i{}, j{};
        while(j<=word.size()){
            cout<<i<<" "<<j<<endl;
            while(j<word.size() && word[i] == word[j]) j++;

                int occ = j -i;
                while(occ>9){
                    ans+='9';
                    ans+=word[i];
                    occ-=9;
                }
                ans+= (char)(occ + '0');
                ans+=word[i];
                i = j;
                if(j == word.size()) break;
        }
        return ans;
    }
};