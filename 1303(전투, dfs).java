import java.util.Scanner;

public class Main {
    public static int n, m;
    public static char[][] map = new char[105][105];
    public static boolean[][] visit = new boolean[105][105];
    public static int w = 0, b = 0;
    public static int[] dr = {-1, 0, 1, 0};
    public static int[] dc = {0, -1, 0, 1};

    public static boolean isIn(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    public static int dfs(int r, int c, char ch) {
        visit[r][c] = true;
        int res = 1;
        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if(isIn(nr, nc) && !visit[nr][nc] && map[nr][nc] == ch){
                int chRes = dfs(nr, nc, ch);
                res += chRes;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        //n행 m열
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            for(int j = 0; j < m; j++){
                map[i][j] = s.charAt(j);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'W' && !visit[i][j]) {
                    int res = dfs(i, j, 'W');
                    w += res * res;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'B' && !visit[i][j]) {
                    int res = dfs(i, j, 'B');
                    b += res * res;
                }
            }
        }

        System.out.println(w + " " + b);
    }
}