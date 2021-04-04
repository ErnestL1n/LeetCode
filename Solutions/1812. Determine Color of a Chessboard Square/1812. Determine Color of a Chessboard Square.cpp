class Solution {
public:
    bool squareIsWhite(string coo) {
        return (coo[0]-'a'+coo[1]-'1')%2;
    }
};