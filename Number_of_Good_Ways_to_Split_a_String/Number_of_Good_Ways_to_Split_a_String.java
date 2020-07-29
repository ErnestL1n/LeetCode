/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1525
public class Number_of_Good_Ways_to_Split_a_String {

	/**
	 * @param args
	 */
    public static int numSplits(String s) {
    char[] str=s.toCharArray();
    int[] freq=new int[26], left=new int[26];
    int res=0, ct=0, ctl=0;
    for(int i=0;i<str.length;i++) {
        if(freq[str[i]-'a']==0) ct++;
        freq[str[i]-'a']++;
    }
    for(int i=0;i<str.length;i++) {
        if(left[str[i]-'a']==0) ctl++;
        left[str[i]-'a']++;
        freq[str[i]-'a']--;
        if(freq[str[i]-'a']==0) ct--;
        if(ctl==ct) res++;
        else if(ctl>ct) return res;
    }
    return res;
}
	public static void main(String[] args) {
		

	}

}
