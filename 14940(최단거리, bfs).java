import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

class Pair{
    public Pair(int r, int c) {
        this.r = r;
        this.c = c;
    }

    public int r;
    public int c;
}

public class Main {
    public static int[][] map;
    public static int[][] visit;
    public static int n, m;
    public static Queue<Pair> q = new LinkedList<>();
    public static int[] dr = {-1, 0, 1, 0};
    public static int[] dc = {0, -1, 0, 1};

    public static boolean isIn(int r, int c) {
        return r > 0 && r <= n && c > 0 && c <=m;
    }

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder builder = new StringBuilder();

        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        map = new int[n + 1][m + 1];
        visit = new int[n + 1][m + 1];

        int r = 0, c = 0;

        for (int i = 1; i <= n; i++) {
            String[] strArray = br.readLine().split(" ");
            List<Integer> list = new ArrayList<>(Arrays.stream(strArray).map(Integer::parseInt).collect(Collectors.toList()));
            list.add(0, 0);
            map[i] = list.stream().mapToInt(e -> e).toArray();
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 2) {
                    r = i; c = j;
                    visit[i][j] = -1;
                }
                else if(map[i][j] == 1){
                    visit[i][j] = -1;
                }
                else if (map[i][j] == 0) {
                    visit[i][j] = 0;
                }
            }
        }

        visit[r][c] = 0;
        q.add(new Pair(r, c));

        while (!q.isEmpty()) {
            Pair x = q.poll();

            for (int k = 0; k < 4; k++) {
                int nr = x.r + dr[k];
                int nc = x.c + dc[k];
                if (isIn(nr, nc) && visit[nr][nc] == -1) {
                    visit[nr][nc] = visit[x.r][x.c] + 1;
                    q.add(new Pair(nr, nc));
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                builder.append(visit[i][j] + " ");
            }
            builder.append('\n');
        }

        String ans = builder.toString();
        System.out.println(ans);
    }
}