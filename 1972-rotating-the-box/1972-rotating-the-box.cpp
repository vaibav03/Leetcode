class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(int i=0;i<box.size();i++){
            int j = box[0].size()-1;
            queue<int> q;
            while(j>=0){
                if(box[i][j]=='.')
                q.push(j);

                else if(box[i][j]=='*'){
                    while(!q.empty())
                    q.pop();
                }

                else if(!q.empty()){ 
                 box[i][q.front()] = '#';
                 box[i][j]='.';
                 q.pop();
                 q.push(j);
                }
                j--;
            }
            while(!q.empty()){
                box[i][q.front()] = '.';
                q.pop();
            }
        }
            int m = box.size();
            int n = box[0].size();
            vector<vector<char>> rotated(n, vector<char>(m));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][m - 1 - i] = box[i][j]; 
        }
    }
    return rotated;

    }
};