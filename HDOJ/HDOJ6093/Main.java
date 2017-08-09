import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    final static long mod=998244353L;
    final static long JC[]=new long[1600];

    public static void main(String[] args) throws Exception {
//        FileInputStream fis=new FileInputStream("1009.in");
//        System.setIn(fis);
        Scanner sc=new Scanner(System.in);

        JC[0]=1L;
        for (int i=1; i<1600; i++) {
            JC[i]=JC[i-1]*i;
            JC[i]%=mod;
        }


        int T=sc.nextInt();
        while ((T--)>0) {
            BigInteger L=sc.nextBigInteger();
            BigInteger R=sc.nextBigInteger();
//            System.out.println(func(R));
//            System.out.println(func(L.subtract(BigInteger.ONE)));
//            System.out.println("ans");
            System.out.println((func(R)-func(L.subtract(BigInteger.ONE))+mod)%mod);
        }
    }
    static Stack myCov(BigInteger N,int d) {
//        System.out.println("DEBUG==");
        Stack st=new Stack();
        BigInteger D=BigInteger.valueOf(d);
        while (!N.equals(BigInteger.ZERO)) {
            st.push(N.mod(D).intValue());
            N=N.divide(D);
        }
//		while(!st.empty()) {
//			System.out.println(st.peek());
//			st.pop();
//		}
        return st;
    }
    static long func(BigInteger N) {
        long lgN=N.toString().length();
        lgN*=(100000L);
        if (N.equals(BigInteger.ONE)||N.equals(BigInteger.ZERO)) {
            return 0;
        }

        else {
            int l=2,r=1600;
            while ((r-l)>1) {
                int mid=(l+r)>>1;
                long lgdl=(mid-1)*(long)(Math.floor((double)100000*Math.log10((double)mid)));
                long lgdr=mid*(long)(Math.ceil((double)100000*Math.log10((double)mid)));
                if (lgdl>(lgN))
                    r=mid;
                else if (lgdr<(lgN-100000L))
                    l=mid;
                else {
                    Stack cov = myCov(N, mid);
                    if (cov.size() >= mid) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
            }
            long rst=0L;

            for (int i=2; i<l; i++) {
                rst+=(JC[i-1]*(i-1));
                rst%=mod;
            }

            Stack cov=myCov(N, l);
            long[] A=new long[1600];
            boolean[] B=new boolean[1600];
            int lft=l;


            if (cov.size()==l) {
                boolean cz=true;
                while (!cov.empty()) {
                    int sum=0;
                    for (int i=0; i<(int)cov.peek(); i++) {
                        if (!B[i]) {
                            sum++;
                        }
                    }
                    if (cz) {
                        cz=false;
                        rst+=(sum-1)*JC[lft-1];
                        rst%=mod;
                        B[(int)cov.peek()]=true;
                        lft--;
                        cov.pop();
                    }
                    else {
                        if (sum!=0) {
                            rst+=sum*JC[lft-1];
                            rst%=mod;
                        }
                        if (!B[(int)cov.peek()]) {
                            B[(int)cov.peek()]=true;
                            lft--;
                            cov.pop();
                            if (cov.empty())
                                rst++;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            else {
                rst+=(JC[l-1]*(l-1));
                rst%=mod;
            }
            return rst;
        }
    }
}
