import java.io.*;
import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()) {
            BigInteger n=cin.nextBigInteger();
            BigInteger ans=n.multiply(n.subtract(BigInteger.ONE));

            String bit=n.toString(2);
            BigInteger tans=BigInteger.ZERO;
            int len=bit.length();
            for (int i=1; i<(len-1); i++) {
                BigInteger ttans=BigInteger.ZERO;
                BigInteger l=new BigInteger(bit.substring(0,i),2);
                BigInteger r=new BigInteger(bit.substring(i+1, len),2);
                if (bit.charAt(i)=='1') {
                    ttans=l.multiply(BigInteger.ONE.shiftLeft(len-i-1).subtract(r).subtract(BigInteger.ONE));
                }
                else {
                    ttans=l.multiply(r.add(BigInteger.ONE));
                }

                tans=tans.add(ttans.multiply(BigInteger.ONE.shiftLeft(len-i-1)));
            }
            if (bit.charAt(len-1)=='0') {
                tans=tans.add(new BigInteger(bit.substring(0,len-1),2));
            }
            System.out.println(ans.subtract(tans.multiply(new BigInteger("2"))));
        }
    }
}
