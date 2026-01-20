class MagicDictionary {
public:
    unordered_map<string,int> dict;

    void buildDict(vector<string> dictionary) {
        for(auto x : dictionary){ dict[x]++; }
    }

    bool search(string searchWord) {
        for(int i=0;i<searchWord.length();i++){ 
            int original = searchWord[i]; 
            for(int j=0;j<26;j++){ 
               searchWord[i] = (char) 'a' + j ; 
                if(searchWord[i] != original && dict.find(searchWord)!=dict.end() ) 
                return true;
             } 
             searchWord[i] = original;
        } 
    return false;
    }
};
