/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
class ListNode{
	int val;
	ListNode next;
	ListNode(){};
	ListNode(int value){this.val=value;};
	ListNode(ListNode next,int value){
		this.next=next;
		this.val=value;
	};
	
}
public class Middle_of_the_Linked_List {

	/**
	 * @param args
	 */
	
    public ListNode middleNodeFastAndSlow(ListNode head) {
        ListNode slow=head,fast=head;
        while(fast!=null&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    
    public ListNode middleNode(ListNode head) {
        ListNode[] A=new ListNode[100];
        int t=0;
        while(head.next!=null){
            A[t++]=head;
            head=head.next;
        }
        return A[t/2];
    }
	public static void main(String[] args) {

	}

}
