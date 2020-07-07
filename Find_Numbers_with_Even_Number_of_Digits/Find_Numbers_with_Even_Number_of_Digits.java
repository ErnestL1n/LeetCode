/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1295
public class Find_Numbers_with_Even_Number_of_Digits {

	/**
	 * @param args
	 */
	public static int findNumbers(int[] nums) {
        int answer=0;
        for(int number:nums){
            //By the help of string valueOf() method, you can convert int to string
            //length() is a method on java.lang.String, which is just a thin wrapper on a char[] anyway.
            int length=String.valueOf(number).length();
            if(length%2==0)
                answer++;
        }
        return answer;
    }
	
	public static int findNumbersWithConstraints(int[] nums) {
        int res=0;
        for(int a:nums){
            if((9<a&&a<100)||(999<a&&a<10000)||a==100000)
                res++;
        }
        return res;
    }
	
	public static int findNumbersOneLine(int[] nums) {
		return (int) Arrays.stream(nums).filter(num -> String.valueOf(num).length() % 2 == 0).count();
    }
	
	
	public static void main(String[] args) {
		int[] nums=new int[] {12,345,2,6,7896};
		System.out.println("Given an array of integers : "+Arrays.toString(nums));
		System.out.println("return how many of them contain an even number of digits : "+findNumbersWithConstraints(nums));
	}

}
