/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1455
public class Check_If_a_Word_Occurs_As_a_Prefix_of_Any_Word_in_a_Sentence {

	/**
	 * @param args
	 */
	public int isPrefixOfWordWithoutMethod(String sentence, String searchWord) {
        boolean search=true;
        for(int i=0,j=0,wordcount=1;i<sentence.length();++i){
            if(search){
                if(sentence.charAt(i)==searchWord.charAt(j)){
                    ++j;
                    if(j==searchWord.length())
                        return wordcount;
                }
                else search=false;
            }
            if(sentence.charAt(i)==' '){
                j=0;
                ++wordcount;
                search=true;
                }
        }
        return -1;
    }
	
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" ");
        for (int i=1; i<=words.length;++i)
            if(words[i-1].indexOf(searchWord)==0) //if (words[i - 1].startsWith(searchWord)) 
            	return i; 
        return -1; 
    } 
	
	public static void main(String[] args) {

	}

}
