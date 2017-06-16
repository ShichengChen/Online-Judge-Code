import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		final int MAXN = 2005;
		BigInteger [] d = new BigInteger[MAXN];
		int c [] = {6,2,5,5,4,5,6,3,7,6};
		for(int i = 0;i < MAXN;i++)
			d[i] = BigInteger.ZERO;
		d[0] = BigInteger.ONE;
		d[6] = BigInteger.valueOf(-1);
		for(int i = 0;i < MAXN;i++)
		{
			for(int j = 0;j < 10 && c[j] + i < MAXN;j++)
			{
				d[i + c[j]] = d[i + c[j]].add(d[i]);
			}
			
		}
		d[6] = d[6].add(BigInteger.ONE);
		d[0] = BigInteger.ZERO;
		for(int i = 1;i < MAXN;i++)
			d[i] = d[i].add(d[i - 1]);
		while(cin.hasNext()){
			int n;
			n = cin.nextInt();
			System.out.println(d[n]);
		}
	}

}
