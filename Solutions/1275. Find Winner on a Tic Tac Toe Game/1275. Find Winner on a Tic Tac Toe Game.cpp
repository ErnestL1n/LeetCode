class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> arow(3),acol(3),brow(3),bcol(3);
        int ad1=0,ad2=0,bd1=0,bd2=0;
        for(int i=0;i<moves.size();++i){
            int r=moves[i][0],c=moves[i][1];
            if(i%2==1){
                if(++brow[r]==3 or ++bcol[c]==3 or (r==c and ++bd1==3) or (r+c==2 and ++bd2==3))
                    return "B";
            }else{
                if(++arow[r]==3 or ++acol[c]==3 or (r==c and ++ad1==3) or (r+c==2 and ++ad2==3))
                    return "A";
            }
        }
        return moves.size()==9?"Draw":"Pending";
    }
};