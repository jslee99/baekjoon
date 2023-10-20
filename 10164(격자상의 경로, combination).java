import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static long[][] c = new long[100][100];

    public static long comb(int n, int r) {
        try {
            if (n == r || r == 0) {
                return 1L;
            } else if (r == 1) {
                return n;
            } else {
                if (c[n][r] != 0) {
                    return c[n][r];
                } else {
                    long res = comb(n - 1, r - 1) + comb(n - 1, r);
                    c[n][r] = res;
                    return res;
                }
            }
        } catch (Exception e) {
            System.out.println(n);
            System.out.println(r);
            throw e;
        }

    }

    public static void main(String[] args) throws IOException {
        int n, m, k;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        k = Integer.parseInt(s[2]);

        if (k == 0) {
            System.out.println(comb (n + m - 2, n - 1));
        }else{
            int r;
            int c;
            if(k % m == 0){
                r = k / m;
                c = m;
            }else{
                r = k / m + 1;
                c = k % m;
            }
            long ans =  comb(r + c - 2, r - 1) * comb(n - r + m - c, n - r);
            System.out.println(ans);
        }
    }
}