class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        set<int> toRemove;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()) toRemove.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()){ toRemove.insert(st.top()); st.pop(); }
        int i{},j{};
        string ans = "";
        
        for(int ind = 0;ind<s.size();ind++){
            if(toRemove.find(ind) == toRemove.end())
            ans+=s[ind];
        }
        return ans;

    }
};