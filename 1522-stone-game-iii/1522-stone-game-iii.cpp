class Solution {
public:
    string stoneGameIII(vector<int>& s) {
     int n = s.size();
     int i0{},i1{},i2{};
     int i = n-1;
     while(i>=0){
      int ans=INT_MIN;

      ans=max(ans,s[i]-i0);

      if(i+1<s.size())
      ans=max(ans,s[i+1]+s[i]-i1);

      if(i+2<s.size())
      ans=max(ans,s[i+2]+s[i+1]+s[i]-i2);
      
      i2=i1;
      i1=i0;
      i0=ans;
      i--;
     }

     if(i0>0)
     return"Alice";
     else if(i0==0)
     return "Tie";
     else
     return "Bob"; 
    }   
};