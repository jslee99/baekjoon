import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

class Pair{
    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public int first;
    public int second;
}

public class Main {
    public static int n;
    public static int m;
    public static ArrayList<Pair>[] map;
    public static boolean[] visit;
    public static int[][] dist;

    public static void dfs(int s, int x, int d) {
        visit[x] = true;
        dist[s][x] = d;
        map[x].forEach(p -> {
                    if(!visit[p.first]) dfs(s, p.first, d + p.second);
                });
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        map = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            map[i] = new ArrayList<>();
        }

        dist = new int[n + 1][n + 1];


        for (int i = 0; i < n - 1; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            map[a].add(new Pair(b, c));
            map[b].add(new Pair(a, c));
        }

        for (int i = 1; i <= n; i++) {
            visit = new boolean[n + 1];
            dfs(i, i, 0);
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println(dist[a][b]);
        }

        return;
    }
}