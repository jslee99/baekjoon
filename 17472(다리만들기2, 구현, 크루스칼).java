import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main{
    static class TRI{
        int a;
        int b;
        int d;
        public TRI(int a, int b, int d) {
            this.a = a;
            this.b = b;
            this.d = d;
        }

        @Override
        public String toString() {
            return a + " " + b + ' ' + d;
        }
    }
    static int N, M, ans;
    static int[][] grid;
    static int[] di = {-1, 0, 1, 0}, dj = {0, -1, 0, 1};
    static PriorityQueue<TRI> pq;
    static int[] parent;

    static boolean isIn(int i, int j){
        return i >= 0 && i < N  && j >= 0 && j < M;
    }
    static void dfs(int i, int j, int num){
        grid[i][j] = num;
        for(int d = 0; d < 4; d++){
            int ni = i + di[d], nj = j + dj[d];
            if(isIn(ni, nj) && grid[ni][nj] == -1)
                dfs(ni, nj, num);
        }
    }

    static int find(int x){
        if(x == parent[x]) return x;
        else return parent[x] = find(parent[x]);
    }

    static void union(int x, int y){
        parent[find(x)] = find(y);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
        grid = new int[N][M];
        ans = 0;
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine(), " ");
            for(int j = 0; j < M; j++){
                grid[i][j] = Integer.parseInt(st.nextToken());
                if(grid[i][j] == 1)
                    grid[i][j] = -1;
            }
        }
        pq = new PriorityQueue<>(new Comparator<TRI>() {
            @Override
            public int compare(TRI o1, TRI o2) {
                return Integer.compare(o1.d, o2.d);
            }
        });

        int temp = 1;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(grid[i][j] == -1)
                    dfs(i, j, temp++);

        parent = new int[temp];
        for(int i = 1; i < temp; i++)
            parent[i] = i;

        int aa = 1;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] > 0){
                    int curNum = grid[i][j];
                    for(int d = 0; d < 4; d++){
                        int ni = i + di[d], nj = j + dj[d];
                        if(!isIn(ni, nj) || grid[ni][nj] == curNum)
                            continue;

                        while(isIn(ni, nj) && grid[ni][nj] == 0){
                            ni += di[d];
                            nj += dj[d];
                        }

                        if(isIn(ni, nj)){
                            pq.offer(new TRI(grid[i][j], grid[ni][nj], Math.abs(i - ni) + Math.abs(j - nj) - 1));
                        }
                    }
                }
            }
        }

        while (!pq.isEmpty()) {
            TRI x = pq.poll();
            if(x.d < 2)
                continue;
            if(find(x.a) != find(x.b)){
                union(x.a, x.b);
                ans += x.d;
            }
        }

        int root = find(1);
        boolean connect = true;
        for(int i = 2; i < temp; i++)
            if(root != find(i))
                connect = false;

        System.out.println(connect ? ans : -1);
    }
}