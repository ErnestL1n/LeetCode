/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.344
public class Reverse_String {

	/**
	 * @param args
	 */
	public static void reverseString(char[] s) {
        int left=0,right=s.length-1;
        while(left<right){
            char temp=s[left];
            s[left++]=s[right];
            s[right--]=temp;
        }
    }
	public static void main(String[] args) {
		
		char[] str = {'h','e','l','l','o'};
		
		System.out.println("String is " + Arrays.toString(str)); 
		reverseString(str);
		System.out.println("String after reversing is " + Arrays.toString(str));

	}

}
