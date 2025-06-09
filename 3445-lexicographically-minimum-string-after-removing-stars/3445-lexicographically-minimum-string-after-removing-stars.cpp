
    struct ComparisonClass {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] > b[0]) return true;
        if (a[0] < b[0]) return false;

        return a[1] < b[1];
    }
};

class Solution {
public:
    string clearStars(string s) {
        priority_queue<vector<int>, vector<vector<int>>, ComparisonClass> pq;
        string ans="";
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' && !pq.empty()) {
                auto x = pq.top();
                pq.pop();
                v.push_back(x[1]);
            }
            if(s[i]!='*'){
                 pq.push({(int)s[i],i});
                 }
            }
        
        sort(v.begin(),v.end());
            int i{},j{};
            while(i<s.size() && j<v.size()){
                while(i != v[j]){
                    if(s[i]!='*')
                    ans+=s[i];

                    i++;
                }
                j++;
                i++;
            }
            while(i <s.size()){
                if(s[i]!='*')
                    ans+=s[i];
                    i++;
                }
                return ans;
    }
};