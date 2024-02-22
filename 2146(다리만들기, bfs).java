import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main{
    static class Pos{
        int r;
        int c;

        public Pos(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    static int N, ans;
    static int[][] grid;
    static int[] di = {-1, 0, 1, 0}, dj = {0, -1, 0, 1};
    static int[] parent;

    static boolean isIn(int i, int j){
        return i >= 0 && i < N  && j >= 0 && j < N;
    }
    static void dfs(int i, int j, int num){
        grid[i][j] = num;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(isIn(ni, nj) && grid[ni][nj] == 1)
                dfs(ni, nj, num);
        }
    }

    static void simulateBfs(int v){
        int[][] tmp = new int[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                tmp[i][j] = grid[i][j];
        ArrayDeque<Pos> q = new ArrayDeque<>();
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(tmp[i][j] == v)
                    for(int d = 0; d < 4; d++){
                        int ni = i + di[d], nj = j + dj[d];
                        if(isIn(ni, nj) && tmp[ni][nj] == 0){
                            tmp[ni][nj] = 1;
                            q.offer(new Pos(ni, nj));
                        }
                    }
        int aa = 1;
        label:while(!q.isEmpty()){
            Pos p = q.poll();
            for(int d = 0; d < 4; d++){
                int nr = p.r + di[d], nc = p.c + dj[d];
                if(!isIn(nr, nc))
                    continue;

                if(tmp[nr][nc] == 0){
                    tmp[nr][nc] = tmp[p.r][p.c] + 1;
                    q.offer(new Pos(nr, nc));
                } else if (tmp[nr][nc] < 0 && tmp[nr][nc] != v) {
                    ans = Math.min(ans, tmp[p.r][p.c]);
                    break label;
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        grid = new int[N][N];
        ans = Integer.MAX_VALUE;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j = 0; j < N; j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int islandNum = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(grid[i][j] == 1)
                    dfs(i, j, --islandNum);

        Set<Integer> set = new HashSet<>();

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(grid[i][j] < 0){
                    if(!set.contains(grid[i][j])){
                        simulateBfs(grid[i][j]);
                        set.add(grid[i][j]);
                    }
                }

        System.out.println(ans);

    }
}