import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	 public static void main(String args[])  
	    {  
	        Scanner cin = new Scanner(System.in);
	        int _ = cin.nextInt();
	        while(_-- > 0)
	        {
	        	int n;
	        	n = cin.nextInt();
	        	BigInteger ans = new BigInteger("4");
	        	for(int i  = 1;i < n;i++)
	        		ans = ans .multiply(BigInteger.valueOf(4));
	        	System.out.println(ans.subtract(BigInteger.valueOf(1)).divide(BigInteger.valueOf(3)));
	        }
	    } 
}
