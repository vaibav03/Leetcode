class Solution {
public:
     bool func(vector<int>& arr, vector<int> &visited,int i)
    {
        if(i<0||i>=arr.size()||visited[i]==1) return false;
        if(arr[i]==0) return true;
        visited[i]=1;
        return func(arr,visited,i-arr[i])||func(arr,visited,i+arr[i]);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(),0);
        return func(arr,visited,start);
    }
};