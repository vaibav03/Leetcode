class Solution {
public:
    string robotWithString(string s){
        vector<int> nextSmall(s.size());
        int mine=INT_MAX;
        for(int i=s.size()-1;i>=0;i--){
            mine = min(mine,(int)s[i]);
            if(mine == (int) s[i]){ 
                nextSmall[i] = i;
            }else{
                nextSmall[i] = nextSmall[i+1];
            }
        }

        stack<int> t;
        int ind = 0;
        string ans ="";
        while(ind<s.size()){
            if(nextSmall[ind] == ind){
                int tope = INT_MAX;
                if(!t.empty())
                tope = min(tope,t.top());

                if(tope<s.size() && s[tope]<=s[ind]){
                    t.pop();
                    ans+=s[tope];

                }else{
                    ans+=s[ind];
                    ind++;
                }
            }else{
                while(!t.empty() && s[t.top()]<=s[nextSmall[ind]]){
                    ans+=s[t.top()];
                    t.pop();
                }
                while(ind<s.size() && ind != nextSmall[ind]){
                    t.push(ind);
                    ind++;
                }
            }
        }

        while(!t.empty()){
            ans+=s[t.top()];
            t.pop();
        }
        return ans;

    }
};