class Solution {
public:
    vector<string> ans;
     unordered_map<char, string> dL = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void allComb(string digits,int ind,string &curr){
        if(ind == digits.size()) {
            if(curr!="")
            ans.push_back(curr);
            return;
        }
    curr+=dL[digits[ind]][0];
    allComb(digits,ind+1,curr);
    curr.pop_back();

    curr+=dL[digits[ind]][1];
    allComb(digits,ind+1,curr);
    curr.pop_back();

    curr.push_back(dL[digits[ind]][2]);
    allComb(digits,ind+1,curr);
    curr.pop_back();

    if(digits[ind] == '7' || digits[ind] == '9'){
    curr.push_back(dL[digits[ind]][3]);
    allComb(digits,ind+1,curr);
    curr.pop_back();
    }
    }
    vector<string> letterCombinations(string digits) {
        string curr = "";
        allComb(digits,0,curr);
        return ans;
    }
};