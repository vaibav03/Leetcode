class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        for(int k=1;k<=s.size();k++){
            reverse(s.begin(),s.begin()+k);
            //cout<<s<<endl;
            if(s < ans) ans = s;
            reverse(s.begin(),s.begin()+k);
        }

        for(int k=1;k<=s.size();k++){
            reverse(s.end()-k , s.end());
            //cout<<s<<endl;
            if(s < ans) ans = s;
            reverse(s.end()-k , s.end());
        }
        return ans;
    }
};