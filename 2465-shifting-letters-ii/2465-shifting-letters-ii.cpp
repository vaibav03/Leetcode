class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pre(n,0);
        for(int i=0;i<shifts.size();i++){
            if(shifts[i][2]==1)
            {
                pre[ shifts[i][0] ] += 1;
                if( shifts[i][1]+1 < s.size() )
                pre[shifts[i][1]+1] -= 1;
            }
            else{
                pre[shifts[i][0]] -= 1;
                if( shifts[i][1]+1 < n )
                pre[shifts[i][1] + 1] += 1;
            } 
        }
        for(int i=0;i<pre.size();i++){
            if(i!=0){
                pre[i]+=pre[i-1];
            }
            int x = (s[i] - 'a' + pre[i])%26;
            if (x < 0) x += 26; 
            s[i] = 'a'+ x;
        }
        return s;
    }
};