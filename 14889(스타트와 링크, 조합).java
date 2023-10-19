import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static int n;
    static int [][] m = new int[25][25];
    static boolean[] t = new boolean[25];
    static int ans = 999999;

    public static void calc() {
        int ts = 0;
        int fs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(t[i] && t[j]){
                    ts += m[i][j];
                }
                if(!t[i] && !t[j]){
                    fs += m[i][j];
                }
            }
        }
        ans = Integer.min(ans, Math.abs(ts - fs));
    }

    public static void comb(int idx, int num) {
        if (num == n / 2) {
            calc();
            return;
        }

        for (int i = idx + 1; i < n; i++) {
            t[i] = true;
            comb(i, num + 1);
            t[i] = false;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a = sc.nextInt();
                m[i][j] = a;
            }
        }

        for(int i = 0; i < n; i++) t[i] = false;

        comb(-1, 0);

        System.out.println(ans);

        return;
    }
}
