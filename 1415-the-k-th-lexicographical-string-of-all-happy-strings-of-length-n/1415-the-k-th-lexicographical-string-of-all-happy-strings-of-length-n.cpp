class Solution {
public:
    vector<string> src;

    void generate(string &curr, int n){

        if(curr.size() == n){
            src.push_back(curr);
            return;
        }

        if(curr.empty() || curr.back() != 'a'){
            curr.push_back('a');
            generate(curr, n);
            curr.pop_back();
        }

        if(curr.empty() || curr.back() != 'b'){
            curr.push_back('b');
            generate(curr, n);
            curr.pop_back();
        }

        if(curr.empty() || curr.back() != 'c'){
            curr.push_back('c');
            generate(curr, n);
            curr.pop_back();
            }
    }

    string getHappyString(int n, int k) {

        string curr = "";
        generate(curr, n);

        sort(src.begin(), src.end());

        return (src.size() >= k) ? src[k-1] : "";
    }
};