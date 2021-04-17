class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        bool search=true;
        for(int i=0,j=0,wordcnt=1;i<sentence.size();++i){
            if(search){
                if(sentence[i]==searchWord[j]){
                    ++j;
                    if(j==searchWord.size())
                        return wordcnt;
                }else
                    search=false;
            }
            if(sentence[i]==' '){
                j=0;
                ++wordcnt;
                search=true;
            }
        }
        return -1;
    }
};