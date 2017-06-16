import java.util.*;
public class Main {
	static long gcd(long a,long b)
	{
		long cur;
		while(b != 0)
		{
			cur = a % b;
			a = b;
			b = cur;
		}
		return a;
	}
	public static void main(String args[])
	{
		Scanner cin = new Scanner (System.in);
		long a,b,c;
		while(cin.hasNext())
		{
			a = cin.nextLong();
			b = cin.nextLong();
			c = b / a;
			for(long i = (long)Math.sqrt(c);i >= 1;i--)
			{
				if(c % i == 0 && gcd(i,c / i) == 1)
				{
					System.out.println((a * i) + " " + (b / i));
					break;
				}
			}
		}
	}
	
}