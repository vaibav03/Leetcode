class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice{},bob{};

        for(int i=1;i<colors.size()-1;i++){
            if(colors[i] == 'A' && colors[i-1]=='A' && colors[i+1] == 'A'){
                alice++;
            }

            if(colors[i] == 'B' && colors[i-1]=='B' && colors[i+1] == 'B'){
                bob++;
            }
        }
        cout<<alice<<" "<<bob<<endl;
        return (alice> bob) ? true : false;

    }
};