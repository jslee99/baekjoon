import java.util.PriorityQueue;
import java.util.Scanner;

class pos implements Comparable<pos>{
    public pos(int r, int c, int t) {
        this.r = r;
        this.c = c;
        this.t = t;
    }

    public int r;
    public int c;
    public int t;


    @Override
    public int compareTo(pos o) {
        return this.t <= o.t ? -1 : 1;
    }
}

public class Main {
    public static int n, m, t;
    public static int[] dr = {-1, 0, 1, 0};
    public static int[] dc = {0, -1, 0, 1};
    public static int[][] map;
    public static int[][] visit;
    public static pos s;
    public static int ans;
    public static PriorityQueue<pos> pq = new PriorityQueue<>();

    public static boolean isIn(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        t = sc.nextInt();
        map = new int[n][m];
        visit = new int[n][m];
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {map[i][j] = sc.nextInt(); visit[i][j] = 999999; if(map[i][j] == 2) s = new pos(i, j, 0);}

        pos x = new pos(0, 0, 0);
        pq.add(x);
        while (!pq.isEmpty()) {
            x = pq.poll();
            if(visit[x.r][x.c] != 999999) continue;
            visit[x.r][x.c] = x.t;

            for (int k = 0; k < 4; k++) {
                int new_r = x.r + dr[k], new_c = x.c + dc[k];
                if(!isIn(new_r, new_c) || visit[new_r][new_c] != 999999 || map[new_r][new_c] == 1) continue;

                pos z = new pos(new_r, new_c, x.t + 1);
                pq.add(z);
            }
        }

        ans = Math.min(visit[n - 1][m - 1], visit[s.r][s.c] + Math.abs(n - 1 - s.r) + Math.abs(m - 1 - s.c));
        if (ans <= t) {
            System.out.println(ans);
        }else{
            System.out.println("Fail");
        }
    }
}