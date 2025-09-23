class Solution {
public:

    int compareVersion(string v1, string v2) {
       int i1{},j1{},i2{},j2{},ans = -2;
       while(j1<=v1.size() || j2<=v2.size())
       {
       string s1 = "0" , s2= "0";
       while(j1<v1.size() && v1[j1]!='.') j1++;
       while(j2<v2.size() && v2[j2]!='.') j2++;
        if(j1<=v1.size()) s1 = v1.substr(i1,j1-i1);

        if(j2<=v2.size()) s2 = v2.substr(i2,j2-i2);

        cout<<s1<<" "<<s2<<" "<<endl;

        if(stoi(s1)>stoi(s2)){
            return 1;
        }else if(stoi(s1)<stoi(s2)){
            return -1;
        }else {
            ans = 0;
        }
        i1=++j1;
        i2=++j2;
        }
        return ans;
       }

};