class Solution {
public:
  string minWindow(string s, string t) {
    if(t.size() == 1){
        for(auto x : s){
            if(x == t[0]) return t;
        }
        return "";
    }
       unordered_map<int,int> M;
       for(auto x : t){
        M[x]++;
       }
       int l{}, r = 0,size = 0, ans =  INT_MAX, ar= -1, al = -1;
       
       

       while(r < s.size()){
        if(M[s[r]] > 0) size++;
        M[s[r]]--;
        r++;
        
        //cout<<l<<" "<<r<<" "<<size<<endl;

        while(size == t.size()){ 
            cout<<l<<" "<<r<<endl;
            if(ans > r-l){
                ar = r-1;
                al = l;
                ans = r-l;
            }

           M[s[l]]++;
           if(M[s[l]] > 0 ) size--;
           l++;
        }
        
       }
       cout<<al<<" "<<ans<<endl;
       return (ar!=-1 && al!=-1 ) ?  s.substr(al , ans) : "";
    }
};
