class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        string s1 ="",fin = "";
        int n = nums1.size(); 
        for(int i=0;i<nums1.size();i++){ 
            s1+=(nums1[i]+'0');
            fin+=(nums2[i]+'0');
        }
        queue<string> q;
        unordered_map<string,int> M;
        M[s1] = 0;
        q.push(s1);

        while(!q.empty()){
            string x = q.front();
            q.pop();
            if(x == fin) break;

            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    string ins = x.substr(i,j-i+1);
                    string rem = x.substr(0,i) + x.substr(j+1,n-j+1);
                    for(int k=0;k<=rem.size();k++){
                        string gen = "";
                        gen = rem.substr(0,k) + ins + rem.substr(k,rem.size()-k+1); 
                        if(M.find(gen)==M.end()) {
                            M[gen] =M[x]+1;
                            q.push(gen);
                        }
                    }
                }
            }
        }

        return M[fin];
    }
};