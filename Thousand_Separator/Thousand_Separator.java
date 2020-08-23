/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1556
public class Thousand_Separator {

	/**
	 * @param args
	 */
	public String thousandSeparator(int n) {
        String s=Integer.toString(n),res="";
        for(int i=0;i<s.length();++i){
            if(i>0&&(s.length()-i)%3==0)
                res+=".";
            res+=s.charAt(i);
        }
        return res;
    }
	public static void main(String[] args) {

	}

}
