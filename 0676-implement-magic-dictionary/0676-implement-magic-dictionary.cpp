class MagicDictionary {
public:
    unordered_set<string> dict;

    void buildDict(vector<string> dictionary) {
        for (auto &s : dictionary) {
            dict.insert(s);
        }
    }

    bool search(string searchWord) {
        int n = searchWord.size();
        for (int i = 0; i < n; i++) {
            char original = searchWord[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original) continue;
                searchWord[i] = c;
                if (dict.find(searchWord) != dict.end())
                    return true;
            }
            searchWord[i] = original;
        }
        return false;
    }
};
