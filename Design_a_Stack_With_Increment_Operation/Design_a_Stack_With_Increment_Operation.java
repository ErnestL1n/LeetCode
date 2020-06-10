/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1381
//reference:https://leetcode.com/lee215/
/*Below is a quicker solution for this problem(Leetcode)
//Use an additional array to record the increment value.
//inc[i] means for all elements stack[0] ~ stack[i],
//we should plus inc[i] when popped from the stack.
//Then inc[i-1]+=inc[i], so that we will keep it from next pop.

class CustomerStack{
	
	private static int maxSize;
	private static int[] inc;
	private static Stack<Integer> stack;
	
	public static void show() {
		System.out.println(stack);
	}
	
	public CustomerStack(int maxSize) {
		this.maxSize=maxSize;
		this.stack=new Stack<Integer>();
		this.inc=new int[maxSize];
	}
	public static void push(int x) {
		if(stack.size()<maxSize)stack.push(x);
		else {
			System.out.println("Stack is full !! ,next operation is invalid");
		}
	}
	public static int pop() {
		int i=stack.size()-1;
		if(i<0)return -1;
		if(i<0)inc[i-1]+=inc[i];
		int res=stack.pop()+inc[i];
		inc[i]=0;
		return res;
	}
	public static void increment(int k,int val) {
		k=Math.min(stack.size(), k)-1;
		if(k>=0)inc[k]+=val;
	}
	
}
*/

//Here is the simple but real solution
class CustomerStack{
	
	private static int[] data;
    private static int size;
	private static int top;
	
	public static void show() {
		
		System.out.print("[");
		for(int i=0;i<top;i++)
			System.out.print(data[i]+" ");
		if(top>=0)System.out.print(data[top]);
		System.out.println("]");
	}
	
	public CustomerStack(int maxSize) {
		this.top=-1;
		this.size=maxSize;
		this.data=new int[maxSize];
	}
	public static void push(int x) {
		if(top+1==size)return;
		data[++top]=x;
		
	}
	public static int pop() {
		if(top==-1) {
			System.out.println("Stack is empty, return -1");
			return -1;
			}
		return data[top--];
	}
	public static void increment(int k,int val) {
		for(int i = 0; i <= Math.min(k - 1, top); i++)
            data[i] += val;
	}
	
}

public class Design_a_Stack_With_Increment_Operation {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		int stacksize=3;
		CustomerStack stack=new CustomerStack(stacksize);
		System.out.println("Stack is built Empty =>");
		stack.show();
		stack.push(1);
		System.out.println("push 1 into stack =>");
		stack.show();
		stack.push(2);
		System.out.println("push 2 into stack =>");
		stack.show();
		System.out.println("pop  "+stack.pop()+" from the stack =>");
		stack.show();
		stack.push(2);
		System.out.println("push 2 into stack =>");
		stack.show();
		stack.push(3);
		System.out.println("push 3 into stack =>");
		stack.show();
		stack.push(4);
		System.out.println("push 4 into stack =>");
		stack.show();
		stack.increment(5, 100);
		System.out.println("increment 100 into bottom 5 elements in stack =>");
		stack.show();
		stack.increment(2, 100);
		System.out.println("increment 100 into bottom 2 elements in stack =>");
		stack.show();
		System.out.println("pop  "+stack.pop()+" from the stack =>");
		stack.show();
		System.out.println("pop  "+stack.pop()+" from the stack =>");
		stack.show();
		System.out.println("pop  "+stack.pop()+" from the stack =>");
		stack.show();
		System.out.println("pop  "+stack.pop()+" from the stack =>");
		stack.show();

	}

}
