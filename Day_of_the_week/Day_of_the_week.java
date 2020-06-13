/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1185
public class Day_of_the_week {

	private static String[] days = new String[]{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	/**
	 * @param args
	 */
	public static String dayOfTheWeek(int d, int m, int y) {
		if (m < 3) {
            m += 12;
            y -= 1;
        }
        int c = y / 100;
        y = y % 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return days[(w + 7) % 7];
	}
	public static void main(String[] args) {
		int day=31,month=8,year=2019;
		System.out.println("day = "+day+" , month = "+month+", year = "+year);
        System.out.println("Today is "+dayOfTheWeek(day,month,year));
	}

}
