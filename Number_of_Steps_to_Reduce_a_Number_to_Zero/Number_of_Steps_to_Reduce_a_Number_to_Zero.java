/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1342
public class Number_of_Steps_to_Reduce_a_Number_to_Zero {

	/**
	 * @param args
	 */
    public static int numberOfSteps (int num) {
        if(num==0)return 0;
        int n=num,res=0;
        while(n>0){
            if(n%2==0)n/=2;
            else --n;
            ++res;
        }
        return res;
    }
	public static void main(String[] args) {
		int num=14;
		System.out.println("Given a non-negative integer : "+num);
		System.out.println("Number of steps to reduce it to zero is : "+numberOfSteps(num));

	}

}
