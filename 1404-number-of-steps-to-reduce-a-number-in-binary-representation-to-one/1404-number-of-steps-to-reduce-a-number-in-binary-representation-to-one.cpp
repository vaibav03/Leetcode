class Solution {
public:
    void addOne(string &s){
        int i = s.size() - 2,carry{},val = 1;
        s[s.size() - 1] = '0';
        while(i>=0){
            if(s[i] == '1'){ s[i] = '0'; carry = 1;}
            else {s[i] = '1'; carry = 0; break;}
            i--;
        }
        if(carry == 1){
            string dupe = '1' + s;
            s = dupe;
        }
    }
    void divide(string &s){
        s.pop_back();
    }
    int numSteps(string s) {
        int ans{};
        while(s.size() > 1){
            cout<<s<<" "<<ans<<endl;
            if(s[s.size() - 1] == '1'){ addOne(s); }
            else { divide(s); }
            ans++;
        }
        return ans;
    }
};