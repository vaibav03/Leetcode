class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        multiset<int> ms;
        string pre = "";
        vector<string> vec;
        for(auto x : s) ms.insert(x);

        for(int i=0;i<target.size();i++){
            if(ms.upper_bound(target[i]) != ms.end() )
            {
                
                string temp = pre;
                auto it = ms.upper_bound(target[i]);
                char c = *it; 
                temp+= (c);
                ms.erase(it);
                for(auto x : ms) temp.push_back(x);
                cout<<temp<<endl;
                vec.push_back(temp);
                ms.insert(c);
            }
            if(ms.lower_bound(target[i]) != ms.end()){
            auto it = ms.lower_bound(target[i]);
            pre+=(*it);
            ms.erase(it);
            }else break;
        }
        if(vec.size() == 0 ) return "";

        return *min_element(vec.begin(),vec.end());
    }
};