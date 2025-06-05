class Solution {
public:
    string comp(string a,string b){
        int i{},j{};
        for(int i=0;i<b.size();i++){
            if(a[i]>b[i]){
                return a;
            }else if(b[i]>a[i]){
                return b;
            }
        }
        return a;
    }
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;

        string ans="";
        for(int i=0;i<=numFriends-1;i++){
            string slide(word.begin()+i,word.begin()+i+word.size()-numFriends+1);
             ans = comp(slide,ans);

            if(i==numFriends-1){
                for(int j=0;j<slide.size();j++){
             string x(slide.begin()+j,slide.end());
             ans = comp(ans,x);
                }
            }
        }
        return ans;
    }
};