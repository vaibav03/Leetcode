class Solution {
public:
    bool isPal(string &s, int l,int r , bool skip){
        //cout<<l<<" "<<r<<endl;
        if(l==-1 && r == s.size()) return true;
        else if(l == -1 || r == s.size() ){
            if(skip) return true;
            else return false;
        }

        if(s[l] == s[r]) return isPal(s,l-1,r+1,skip);

        else {
            if(!skip) return false;
            else return isPal(s,l-1,r,false) | isPal(s,l,r+1,false);
        }
        return false;
    }
    bool validPalindrome(string s) {
       int n = s.size();
       bool ans = false;
       if(n%2 == 0){
        int mid1 = n/2-1, mid2 = n/2 ;
        ans|= isPal(s,mid1,mid2,true);
        ans|=isPal(s,mid1,mid1,true);
        ans|=isPal(s,mid2,mid2,true);
       } else{
        ans|=isPal(s,n/2,n/2,true);
        ans|=isPal(s,n/2-1,n/2,true);
        ans|=isPal(s,n/2,n/2+1,true);
       }
     return ans;
    }
};