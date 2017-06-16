import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	public static BigInteger gcd(BigInteger a,BigInteger b)
	{
		if(b.equals(BigInteger.ZERO))
			return a;
		return gcd(b,a.mod(b));
	}
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int _ = cin.nextInt();
		for(int i = 1;i <= _;i++)
		{
			BigInteger a = cin.nextBigInteger(2);
			BigInteger b = cin.nextBigInteger(2);
			a = gcd(a,b);
			System.out.println("Case #"+i+": "+a.toString(2));  
		}
	}
}
