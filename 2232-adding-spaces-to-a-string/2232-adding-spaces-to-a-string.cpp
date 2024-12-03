class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
     int j{};
     string ans ="";
     for(int i=0;i<s.size();i++){
     if(j<spaces.size() && spaces[j] == i)
      {
        ans+=" ";
        ans+=s[i];
        j++;
      }
      else
      ans+=s[i];
     }
     return ans;   

    }
};