import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static BigInteger[] db=new BigInteger[4005];
	public static BigInteger ans;
	public static void init() {
		db[0]=BigInteger.ONE;
		for (int i=1; i<4005; i++) {
			db[i]=db[i-1].multiply(BigInteger.valueOf(2));
		}
	}
	public static void work(BigInteger n,BigInteger m,int now) {
		if (n.compareTo(BigInteger.ZERO)==0)
			return ;
		while (m.multiply(db[now].subtract(BigInteger.ONE)).compareTo(n)>=0)
			now--;
		ans=ans.add(db[now]);
		
		n=n.subtract(db[now].multiply(m.min(n.divide(db[now]))));
		work(n,m,now-1);
	}
	
	public static void main(String[] args) {
		init();
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for (int cas=0; cas<T; cas++) {
			BigInteger n=sc.nextBigInteger();
			BigInteger m=sc.nextBigInteger();
			ans=BigInteger.ZERO;
			
			if (n.mod(m)==BigInteger.ZERO) {
				System.out.println(n.divide(m));
			}
			else {
				int now=0;
				while ((db[now].subtract(BigInteger.ONE)).multiply(m).compareTo(n)<0)
					now++;
				work(n,m,now);
				System.out.println(ans);
			}			
		}
	}
	
}
