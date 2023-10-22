import java.util.*;

class Pair{
    public int r;
    public int c;

    public Pair(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Main {
    public static int[] dc = {-1, -1, 0, 1, 1, 1, 0, -1};
    public static int[] dr = {0, -1, -1, -1, 0, 1, 1, 1};
    public static int[][] map;
    public static boolean[][] can;
    public static Queue<Pair> before = new LinkedList<>();
    public static Queue<Pair> after = new LinkedList<>();
    public static int n, m;

    public static boolean isIn(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        map = new int[n][n];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] = sc.nextInt();

        before.add(new Pair(n - 1, 0));
        before.add(new Pair(n - 1, 1));
        before.add(new Pair(n - 2, 0));
        before.add(new Pair(n - 2, 1));

        for (int i = 0; i < m; i++) {
            int d,s;
            d = sc.nextInt();
            s = sc.nextInt();
            d--;

            while (!before.isEmpty()) {
                Pair p = before.poll();
                int mr = p.r + dr[d] * s;
                int nr = mr >= 0 ? mr % n : n + mr % n;
                if(nr == n) nr = 0;

                int mc = p.c + dc[d] * s;
                int nc = mc >= 0 ? mc % n : n + mc % n;
                if(nc == n) nc = 0;
                after.add(new Pair(nr, nc));
            }

            can = new boolean[n][n];
            Arrays.stream(can).forEach(c -> Arrays.fill(c, true));

            after.forEach(a -> {
                can[a.r][a.c] = false;
                map[a.r][a.c]++;
            });
            after.forEach(a -> {
                int nr, nc;
                for (int k = 1; k < 8; k += 2) {
                    nr = a.r + dr[k];
                    nc = a.c + dc[k];
                    if (isIn(nr, nc) && map[nr][nc] > 0) map[a.r][a.c]++;
                }
            });
            after.clear();

            for(int a = 0 ; a < n; a++){
                for (int b = 0; b < n; b++) {
                    if (can[a][b] && map[a][b] >= 2) {
                        map[a][b] -= 2;
                        before.add(new Pair(a, b));
                    }
                }
            }
            continue;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans += map[i][j];
        System.out.println(ans);
    }
}