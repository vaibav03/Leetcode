class Solution {
public:
    int minAddToMakeValid(string s){
        int inc{},dec{},ans{};
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                if(inc<0){ ans+=abs(inc); inc=0; }
                inc++;
            }else{
               inc--;
            }
        }

        return  ans + abs(inc);
    }
};