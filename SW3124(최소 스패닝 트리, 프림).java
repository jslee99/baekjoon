import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
 
class Solution{
    static class TRI{
        int b;
        int d;
        public TRI(int b, int d) {
            this.b = b;
            this.d = d;
        }
    }
    static int T, V, E;
    static long distSum;
    static List<TRI>[] graph;
    static boolean[] visit;
    static PriorityQueue<TRI> pq;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine(), " ");
            V = Integer.parseInt(st.nextToken()); E = Integer.parseInt(st.nextToken());
            graph = new List[V + 1];
            visit = new boolean[V + 1];
            distSum = 0;
            for(int i = 1; i <= V; i++)
                graph[i] = new ArrayList<>();
            pq = new PriorityQueue<>((TRI t1, TRI t2) -> Integer.compare(t1.d, t2.d));
            for(int q = 0; q < E; q++){
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
                graph[a].add(new TRI(b, d));
                graph[b].add(new TRI(a, d));
            }
            pq.offer(new TRI(1, 0));
            while(!pq.isEmpty()){
                TRI x = pq.poll();
                if(visit[x.b])
                    continue;
                visit[x.b] = true;
                distSum += x.d;
                for(TRI t : graph[x.b]){
                    pq.offer(t);
                }
            }
            sb.append('#').append(tc).append(' ').append(distSum).append('\n');
        }
        System.out.println(sb);
        br.close();
 
    }
}