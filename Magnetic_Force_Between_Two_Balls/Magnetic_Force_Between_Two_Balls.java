/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1552
public class Magnetic_Force_Between_Two_Balls {

	/**
	 * @param args
	 */
    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int low=0;
        int high=position[position.length-1];
        int optimal=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPut(position,m,mid)){
                optimal=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return optimal;
    }
    private boolean canPut(int[] positions, int m, int max) {
        int count = 1;
        int last = positions[0];
        for (int i = 0; i < positions.length; i++) {
            if (positions[i] - last >= max) {
                last = positions[i];
                count++;
            }
        }
        return count >= m;
    }
	public static void main(String[] args) {

	}

}
