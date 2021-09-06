class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<int,char> max_c={releaseTimes[0],keysPressed[0]};
        for(int i=1;i<releaseTimes.size();++i){
            if(max_c.first<releaseTimes[i]-releaseTimes[i-1])
                max_c={releaseTimes[i]-releaseTimes[i-1],keysPressed[i]};
            if(max_c.first==releaseTimes[i]-releaseTimes[i-1])
                max_c=max_c.second<keysPressed[i]?make_pair(releaseTimes[i]-releaseTimes[i-1],keysPressed[i]):max_c;
        }
        return max_c.second;
    }
};