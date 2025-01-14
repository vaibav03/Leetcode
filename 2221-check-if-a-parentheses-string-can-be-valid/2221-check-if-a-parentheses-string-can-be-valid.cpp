class Solution {
public:
    bool canBeValid(string s, string l) {
        if(s.size()%2) return false;
      stack<int> locked,unlocked;
      int i{};
      while(i<s.size()){
        if(l[i]=='0')
        unlocked.push(i);
        else if(s[i]=='(')
        locked.push(i);
        else if(s[i]==')'){
            if(!locked.empty())
            locked.pop();
            else if(!unlocked.empty())
            unlocked.pop();
            else 
            return false;
        }
        i++;
      } 
      while(!locked.empty() && !unlocked.empty()){
        int lock = locked.top(),unlock = unlocked.top();
        locked.pop();
        unlocked.pop();
        if(unlock<lock) return false;
      }
      if(!locked.empty()) return false;

      return true;
    }
};