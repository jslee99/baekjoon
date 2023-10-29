import java.util.Scanner;

public class Main {
    public static int n, m, r;

    public static int[][] rotation1(int[][] a) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                res[n - 1 - i][j] = a[i][j];
                res[i][j] = a[n - 1 - i][j];
            }
        }
        return res;
    }

    public static int[][] rotation2(int[][] a) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                res[i][m - 1 - j] = a[i][j];
                res[i][j] = a[i][m - 1 - j];
            }
        }
        return res;
    }

    public static int[][] rotation3(int[][] a) {
        int afterN = m;
        int afterM = n;
        int[][] res = new int[afterN][afterM];
        for (int i = 0; i < afterN; i++) {
            for (int j = 0; j < afterM; j++) {
                res[i][j] = a[n - 1 - j][i];
            }
        }
        n = afterN;
        m = afterM;
        return res;
    }

    public static int[][] rotation4(int[][] a) {
        int afterN = m;
        int afterM = n;
        int[][] res = new int[afterN][afterM];
        for (int i = 0; i < afterN; i++) {
            for (int j = 0; j < afterM; j++) {
                res[i][j] = a[j][m - 1 - i];
            }
        }
        n = afterN;
        m = afterM;
        return res;
    }

    public static int[][] rotation5(int[][] a) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                res[i][j] = a[i + n / 2][j];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = m / 2; j < m; j++) {
                res[i][j] = a[i][j - m / 2];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = m / 2; j < m; j++) {
                res[i][j] = a[i - n / 2][j];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                res[i][j] = a[i][j + m / 2];
            }
        }
        return res;
    }

    public static int[][] rotation6(int[][] a) {
        int[][] res = new int[n][m];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                res[i][j] = a[i][j + m / 2];
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = m / 2; j < m; j++) {
                res[i][j] = a[i + n / 2][j];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = m / 2; j < m; j++) {
                res[i][j] = a[i][j - m / 2];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                res[i][j] = a[i - n / 2][j];
            }
        }
        return res;
    }


    public static int[][] command(int[][] a, int c) {
        switch (c) {
            case 1:
                return rotation1(a);
            case 2:
                return rotation2(a);
            case 3:
                return rotation3(a);
            case 4:
                return rotation4(a);
            case 5:
                return rotation5(a);
            case 6:
                return rotation6(a);
            default:
                return null;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        r = sc.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = sc.nextInt();

        for (int i = 0; i < r; i++) {
            int c = sc.nextInt();
            a = command(a, c);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
}