class Solution {
public:
    string stoneGameIII(vector<int>& s) {
     int n = s.size();
     vector<int> dp(n+1,0);
     int i = n-1;
     while(i>=0){
      int ans=INT_MIN;

      ans=max(ans,s[i]-dp[i+1]);

      if(i+1<s.size())
      ans=max(ans,s[i+1]+s[i]-dp[i+2]);

      if(i+2<s.size())
      ans=max(ans,s[i+2]+s[i+1]+s[i]-dp[i+3]);

      dp[i]=ans;
      i--;
     }
     int sum = accumulate(s.begin(),s.end(),0)/2;

     if(dp[0]>0)
     return"Alice";
     else if(dp[0]==0)
     return "Tie";
     else
     return "Bob"; 
    }   
};