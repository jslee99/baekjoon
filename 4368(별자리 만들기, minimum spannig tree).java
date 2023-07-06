import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    int N;
    ArrayList<point> points = new ArrayList<>();
    double[][] map;
    boolean[] is_visited;
    PriorityQueue<TRI> pq = new PriorityQueue<>();
    double ans = 0.0;
    class point{
        public double x;
        public double y;
        public point(double x, double y){
            this.x = x;
            this.y = y;
        }
    }

    class TRI implements Comparable<TRI>{
        public int start;
        public int end;
        public double weight;

        public TRI(int start, int end, double weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(TRI o) {
            if(this.weight < o.weight) return -1;
            else if(this.weight > o.weight) return 1;
            else return 0;
        }
    }

    void solution() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());
        map = new double[N][N];
        is_visited = new boolean[N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            double a,b;
            a = Double.parseDouble(st.nextToken());
            b = Double.parseDouble(st.nextToken());
            points.add(new point(a, b));
        }

        for(int i = 0; i < N; i++){
            point pt = points.get(i);
            for(int j = i + 1; j < N; j++){
                point opp_pt = points.get(j);
                double dist = Math.sqrt(Math.pow(pt.x - opp_pt.x, 2) + Math.pow(pt.y - opp_pt.y, 2));
                map[i][j] = dist;
                map[j][i] = dist;
            }
        }

        TRI x;
        pq.add(new TRI(0, 0, 0.0));
        while (!pq.isEmpty()) {
            x = pq.poll();
            if(is_visited[x.end]) continue;

            is_visited[x.end] = true;
            ans += x.weight;

            for(int i = 0; i < N; i++){
                if(x.end == i) continue;

                pq.add(new TRI(x.end, i, map[x.end][i]));
            }
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        new Main().solution();
        return;
    }
}
