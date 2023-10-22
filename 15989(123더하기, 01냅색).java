import java.util.Scanner;

public class Main {
    public static long[][] dp = new long[4][10005];

    public static void main(String[] args) {
        for(int i = 1; i <= 10000; i++) dp[1][i] = 1;
        dp[2][1] = 1;
        dp[2][2] = 2;
        for (int j = 3; j <= 10000; j++) dp[2][j] = dp[1][j] + dp[2][j - 2];

        dp[3][1] = 1;
        dp[3][2] = 2;
        dp[3][3] = 3;
        for(int j = 4; j <= 10000; j++) dp[3][j] = dp[2][j] + dp[3][j - 3];

        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            int a;
            a = sc.nextInt();
            System.out.println(dp[3][a]);
        }
    }
}