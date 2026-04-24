class Solution {
public:
    string smallestString(string s) {
        int op = 1;
        int i{};
        while(i<s.size() && s[i]=='a')  i++;

        if(i == s.size()){ s[s.size()-1] = 'z'; return s;}
        int j = i;
        while(j<s.size() && s[j]!='a') j++;

        cout<<i<<" "<<j<<endl;
        for(int ind = i;ind<j;ind++){
            s[ind]--;
        }
    return s; 
    }
};