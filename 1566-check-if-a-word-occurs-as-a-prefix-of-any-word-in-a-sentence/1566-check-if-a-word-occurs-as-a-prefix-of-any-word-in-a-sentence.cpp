class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordnum = 1; 
        int n = searchWord.size(); 
        int i = 0;

        while (i < sentence.size()) {
            if (sentence.substr(i, n) == searchWord) {
                return wordnum;
            }

            while (i < sentence.size() && sentence[i] != ' ') {
                i++;
            }
            i++; 
            wordnum++; 
        }

        return -1;
    }
};
