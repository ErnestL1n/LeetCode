/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1108
public class Defanging_an_IP_Address {

	/**
	 * @param args
	 */
	public static String defangIPaddr(String address) {
		StringBuilder str=new StringBuilder();
		for(char c:address.toCharArray()) {
			if(c!='.')str.append(c);
			else str.append("[.]");
		}
		return str.toString();
	}
	public static void main(String[] args) {
		String str=new String("255.100.50.0");
		System.out.println("Input: address = "+str);
		System.out.println("Output: "+defangIPaddr(str));

	}

}
