import java.util.Scanner;

public class Main {
    public static int[][] a;
    public static int n, m, r;

    public static void change(int[][] before, int[][] after, int r, int c) {
        int stage = Math.min(Math.min(r, n - r + 1), Math.min(c, m - c + 1));

        if (r == stage && c <= m - stage) {
            after[r][c] = before[r][c + 1];
        } else if (r > stage && c == stage) {
            after[r][c] = before[r - 1][c];
        } else if (r == n - stage + 1 && c > stage) {
            after[r][c] = before[r][c - 1];
        } else if (r <= n - stage && c == m - stage + 1) {
            after[r][c] = before[r + 1][c];
        }else{
            after[r][c] = -1;
        }
    }

    public static int[][] rotation(int[][] before) {
        int[][] after = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                change(before, after, i, j);
            }
        }
        return after;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        r = sc.nextInt();

        a = new int[n + 1][m + 1];

        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) a[i][j] = sc.nextInt();

        int[][] arr = a;
        for(int i = 0; i < r; i++){
            arr = rotation(arr);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
