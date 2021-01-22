/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.187
public class Repeated_DNA_Sequences {

	/**
	 * @param args
	 */
	public List<String> findRepeatedDnaSequences(String s) {
        Set<String> seen=new HashSet<>(),repeated=new HashSet<>();
        for(int i=0;i+9<s.length();++i){
            String ten = s.substring(i, i + 10);
            if(!seen.add(ten))
                repeated.add(ten);
        }
        return new ArrayList(repeated);
    }
	public static void main(String[] args) {
		// TODO 自動產生的方法 Stub

	}

}
