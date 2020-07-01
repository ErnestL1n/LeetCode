/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1491
public class Average_Salary_Excluding_the_Minimum_and_Maximum_Salary {

	/**
	 * @param args
	 */
	
    public static double average(int[] salary) {
        double max=salary[0]>salary[1]?salary[0]:salary[1];
        double min=salary[0]<salary[1]?salary[0]:salary[1];
        double sum=0;
        sum=salary[0]+salary[1];
        for(int i=2;i<salary.length;i++){
            sum+=salary[i];
            if(salary[i]>max)
                max=salary[i];
            else if(salary[i]<min)
                min=salary[i];
        }
        return (sum-max-min)/(salary.length-2);
    }
	public static void main(String[] args) {
		int[] salary=new int[]{48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000};
		System.out.println("Given an array of unique integers salary : ");
		System.out.println(Arrays.toString(salary));
		System.out.println("where salary[i] is the salary of the employee i.");
		System.out.println("Return the average salary of employees excluding the minimum and maximum salary.");
		System.out.println(average(salary));

	}

}
