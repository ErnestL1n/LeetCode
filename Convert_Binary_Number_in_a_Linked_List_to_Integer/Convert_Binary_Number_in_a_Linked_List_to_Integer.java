/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
class ListNode{
	int value;
	ListNode next;
	ListNode(){};
	ListNode(int value){this.value=value;};
	ListNode(int value,ListNode next){
		this.value=value;
		this.next=next;
	}
}

//Leetcode.1290
public class Convert_Binary_Number_in_a_Linked_List_to_Integer {

	/**
	 * @param args
	 */
	//practice linked-list and StringBuffer class
	//reference:https://leetcode.com/sstufetip/
	public int getDecimalValue(ListNode head) {
        //Java StringBuffer class is used to create mutable (modifiable) string
        StringBuffer str=new StringBuffer();
        while(head!=null){
            str.append(head.value);
            head=head.next;
        }
        return Integer.parseInt(str.toString(),2);
    }
	public static ListNode Build(int[] values) {
		if(values.length==0)return null;
		ListNode head=new ListNode(values[0]);
		ListNode temp=new ListNode();
		temp=head;
		for(int i=1;i<values.length;i++) {
			temp=temp.next;
			temp.value=values[i];
		}
		return 
	}
	public static void main(String[] args) {
		

	}

}
