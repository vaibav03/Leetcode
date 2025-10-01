class Solution {
public:
    void assign(string &s,vector<int>& v,int ind){
        for(int i=0;i<52;i++){
            if(v[i]>=1){
                s[ind] = (i>=26) ?  (char) 'a'+i-26 : (char) 'A'+i;
                v[i]--;
                break;
            }
        }
    }
    bool isVowC(char c ){
        return (c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
    bool isVow(char c ){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string sortVowels(string s) {
        int n = s.size();
     vector<int> v(52,0);
     for(int i=0;i<n;i++){
        if(isVow(s[i]))
        v[s[i]-'a' + 26]++;
        else if(isVowC(s[i]))
        v[s[i]-'A']++;
     }
     for(int i=0;i<52;i++){
        if(i<26)
        cout<<(char)('A' + i)<<" "<<v[i]<<endl;
        else
        cout<<(char)('a' + i -26)<<" "<<v[i]<<endl;
     }

    for(int i=0;i<n;i++){
        if(isVow(s[i]) || isVowC(s[i])){
            assign(s,v,i);
        }
    }
    return s;

    }
};