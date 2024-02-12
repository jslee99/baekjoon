import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution{
    static class Microbe{
        int r;
        int c;
        int n;
        int d;

        public Microbe(int r, int c, int n, int d) {
            this.r = r;
            this.c = c;
            this.n = n;
            this.d = d;
        }
    }
    static List<Microbe> microbes;
    static List<Microbe>[][] grid;
    static int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
    static int T, N, M, K;
    static boolean isIn(int r, int c){
        return r > 0 && r < N - 1 && c > 0 && c < N - 1;
    }
    static int reverse(int d){
        switch (d){
            case 0:
                return 1;
            case 1:
                return 0;
            case 2:
                return 3;
            case 3:
                return 2;
            default:
                throw new IllegalStateException();

        }
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
            microbes = new ArrayList<>();
            grid = new List[N][N];
            for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
                grid[i][j] = new ArrayList<>();
            for(int q = 1; q <= K; q++){
                st = new StringTokenizer(br.readLine(), " ");
                int r = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
                d--;
                Microbe m = new Microbe(r, c, n, d);
                grid[r][c].add(m);
                microbes.add(m);
            }
            int ans = 0;

            for(int time = 1; time <= M; time++){
                //이동
                for (Microbe m : microbes) {
                    grid[m.r][m.c].remove(m);
                    m.r += dr[m.d];
                    m.c += dc[m.d];
                    grid[m.r][m.c].add(m);
                }

                //가장자리 처리, 절대 충돌 불가능
                List<Microbe> deletedMicrobes = new ArrayList<>();
                for (Microbe m : microbes) {
                    if(!isIn(m.r, m.c)){
                        m.n /= 2;
                        m.d = reverse(m.d);
                        if(m.n <= 0){
                            deletedMicrobes.add(m);
                        }
                    }
                }
                for (Microbe m : deletedMicrobes) {
                    grid[m.r][m.c].remove(m);
                    microbes.remove(m);
                }

                //겹친부분 처리
                List<int[]> manyPos = new ArrayList<>();
                for (Microbe m : microbes) {
                    if(grid[m.r][m.c].size() > 1){
                        manyPos.add(new int[]{m.r, m.c});
                    }
                }
                for (int[] pos : manyPos) {
                    int r = pos[0];
                    int c = pos[1];
                    int maxN = 0;
                    int sumN = 0;
                    int newDir = -1;
                    for(Microbe m : grid[r][c]){
                        sumN += m.n;
                        if(m.n > maxN){
                            newDir = m.d;
                            maxN = m.n;
                        }
                        microbes.remove(m);
                    }
                    grid[r][c].clear();
                    Microbe microbe = new Microbe(r, c, sumN, newDir);
                    grid[r][c].add(microbe);
                    microbes.add(microbe);
                }
            }

            for (Microbe m : microbes) {
                ans += m.n;
            }

            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}