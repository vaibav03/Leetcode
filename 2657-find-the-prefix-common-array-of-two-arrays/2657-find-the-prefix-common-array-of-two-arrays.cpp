class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq1(51,0),freq2(51,0);
        vector<int> ans;
        int comm{};
        for(int i=0;i<A.size();i++){
            freq1[A[i]]++;
            freq2[B[i]]++;

            if(freq1[A[i]] == 1 && freq2[A[i]] == 1) comm++;
            if(A[i]!=B[i] && freq1[B[i]] == 1 && freq2[B[i]] == 1) comm++;

            ans.push_back(comm);
        }
        return ans;
    }
};