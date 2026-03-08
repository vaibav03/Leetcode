class Solution {
public:
    string res = "";

    void ans(string &x , int n,set<string> &s){

        if(res != "") return;

        if(x.size() == n){
            if(s.find(x)==s.end()) res = x;
            return;
        }

        x+='1';
        ans(x,n,s);
        x.pop_back();

        x+='0';
        ans(x,n,s);
        x.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s(nums.begin(),nums.end());
        int n = nums[0].size();
        string x = "";
        ans(x,n,s);
        return res;
    }
};