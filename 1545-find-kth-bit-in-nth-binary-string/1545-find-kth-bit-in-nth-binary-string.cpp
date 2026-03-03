class Solution {

private:
    string revInvert(string&s){
        const int len = s.size();
        string ans = "";
        for(int i=len-1;i>=0;--i){
            char c = s[i];
            if(c=='0'){ans.push_back('1');}
            else{ans.push_back('0');}
        }
        return ans;
    }

public:
    char findKthBit(int n, int k) {
        string base = "0";
        for(int i=0;i<n-1;++i){
            string Snprev = base;
            base = Snprev + "1" + revInvert(Snprev);
        }
        return base[k-1];
    }
};