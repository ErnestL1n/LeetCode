/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//LeetCode.1370
public class Increasing_Decreasing_String {

	/**
	 * @param args
	 */
	public static String sortString(String s) {
		
		StringBuilder sb=new StringBuilder();
		
		int[] AlphabetCount=new int[26];
		
		//store 0~25<=>a~z
		for(char alphabets:s.toCharArray())AlphabetCount[alphabets-'a']++;
		
		int count=s.length();
		
		while(count!=0) {
			//increasing first
			for(int i=0;i<26;i++)
				if(AlphabetCount[i]>0) {
					sb.append((char)(i+'a'));
					AlphabetCount[i]--;
					count--;
				}
			
			for(int i=25;i!=-1;i--)
				if(AlphabetCount[i]>0) {
					sb.append((char)(i+'a'));
					AlphabetCount[i]--;
					count--;
				}
		}
		
		return sb.toString();
		
	}
	public static void main(String[] args) {
		String Input="leetcode";
		System.out.println("            Original String is           :"+Input);
		System.out.println("Increasing and Decreasing_String becomes :"+sortString(Input));

	}

}