import java.math.BigInteger;
import java.util.Scanner;

public class UVa787 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[] v = new int[105];
        BigInteger[][] dp = new BigInteger[105][105];

        while(in.hasNext()) {
            BigInteger ans = new BigInteger("-99999999");
            int ind = 0, x;

            while((x = in.nextInt()) != -999999)
                v[ind++] = x;

            for(int i=0; i<ind; ++i) {
                for(int j=i; j<ind; ++j) {
                    if(i != j)
                        dp[i][j] = dp[i][j-1].multiply(BigInteger.valueOf(v[j]));
                    else
                        dp[i][j] = BigInteger.valueOf(v[i]);

                    if(ans.compareTo(dp[i][j]) < 0)
                        ans = dp[i][j];
                }
            }
            System.out.println(ans.toString());
        }
    }
}
