class Solution {
public:
    bool differby1(string s1,string s2){
        int i=0,j=0,cnt{};
        while(i<s1.size() && j<s2.size()){
            if(s1[i]!=s2[j])
            cnt++;
            
            i++;
            j++;
        }
        if(cnt==1)
        return true;

        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& w) {
        vector<int> vis(w.size(),0);
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        for(int i=0;i<w.size();i++){
            if(w[i]==beginWord)
            vis[i]=1;
        }
        int ans=INT_MAX;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int i=0;i<w.size();i++){
                if(differby1(node.first,w[i]) && !vis[i]){
                 q.push({w[i],node.second+1});
                 vis[i]=1;
                 if(w[i]==endWord)
                 ans=min(ans,node.second+1);
                }
            }
        }
        if(ans==INT_MAX) return 0;
        
        return ans+1;
    }
};