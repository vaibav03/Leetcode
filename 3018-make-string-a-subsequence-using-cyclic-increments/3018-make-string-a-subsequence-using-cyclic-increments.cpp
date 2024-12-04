class Solution {
public: 

    bool canMakeSubsequence(string str1, string str2) {
        int j = str2.size(),i = str1.size();
        while(i>=0 && j>=0){
         if(str1[i]==str2[j] || str1[i]==str2[j]-1 || (str1[i]=='z' && str2[j]=='a')){
            i--;
            j--;
         }
         else
         i--;
        }
         return (j<0) ? true : false;
    }
};