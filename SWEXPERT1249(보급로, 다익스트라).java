import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

class TRI implements Comparable<TRI>{
    int r;
    int c;
    int d;

    public TRI(int r, int c, int d) {
        this.r = r;
        this.c = c;
        this.d = d;
    }

    @Override
    public int compareTo(TRI o) {
        if(d < o.d){
            return - 1;
        }else{
            return 1;
        }
    }
}

public class Main{
    static int[][] map = new int [105][105];
    static int[][] visit = new int[105][105];
    static int T;
    static int n;
    static PriorityQueue<TRI> pq;
    static int dr[] = {-1, 0, 1, 0};
    static int dc[] = {0, -1, 0, 1};
    static boolean isIn(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            n = Integer.parseInt(br.readLine());
            for(int i = 0; i < n; i++){
                String s = br.readLine();
                for(int j = 0; j < n; j++){
                    map[i][j] = s.charAt(j) - '0';
                    visit[i][j] = Integer.MAX_VALUE;
                }
            }
            pq = new PriorityQueue<>();
            pq.add(new TRI(0, 0, 0));

            while(!pq.isEmpty()){
                TRI x = pq.poll();
                if(visit[x.r][x.c] != Integer.MAX_VALUE)
                    continue;
                visit[x.r][x.c] = x.d;

                for(int d = 0; d < 4; d++){
                    int new_r = x.r + dr[d], new_c = x.c + dc[d];
                    if(isIn(new_r, new_c)){
                        pq.add(new TRI(new_r, new_c, x.d + map[new_r][new_c]));
                    }
                }
            }

            sb.append("#").append(tc).append(" ").append(visit[n - 1][n - 1]).append("\n");
        }
        System.out.println(sb.toString());
    }
}