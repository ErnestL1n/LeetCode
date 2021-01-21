class Solution {
public:
    int maximum69Number (int num) {
        int maxdigit=0,currdigit=1;
		int n=num;
		while(n>0) {
			if(n%10==6)maxdigit=currdigit;
			currdigit*=10;
			n/=10;
		}
		return num+3*maxdigit;
    }
};