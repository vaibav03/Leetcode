class Solution {
public:
    int minChanges(string s) {
        int num=1,op{};
        for(int i=1;i<s.size();i++){
          if(s[i]==s[i-1])
          num++;
          else{
            if(num%2)
            {
             op++;
             num++;
             s[i]=s[i-1];
            }
            else{
               num=1;
            }
        }
        }
        return op;

    }
};