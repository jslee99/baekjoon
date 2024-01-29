import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Solution{
    static int T;
    static int n;
    static int m;
    static List<Integer>[] down = new List[600];
    static List<Integer>[] up = new List[600];
    static int ans;

    static void dfs(int x, List<Integer>[] map, boolean[] visit){
        visit[x] = true;
        for(int i : map[x]){
            if(!visit[i])
                dfs(i, map, visit);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        for(int tc = 1; tc <= T; tc++){
            n = Integer.parseInt(br.readLine());
            for(int i = 1; i <= n; i++){
                down[i] = new ArrayList<>();
                up[i] = new ArrayList<>();
            }
            m = Integer.parseInt(br.readLine());
            ans = 0;
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
                down[a].add(b);
                up[b].add(a);
            }

            for(int i = 1; i <= n; i++){
                if(i == 4){
                    int aa = 0;
                }

                boolean[] downVisit = new boolean[n + 1];
                dfs(i, down, downVisit);
                int cnt = 0;
                for(int j = 1; j <= n; j++)
                    if(downVisit[j])
                        cnt++;

                boolean[] upVisit = new boolean[n + 1];
                dfs(i, up, upVisit);
                for(int j = 1; j <= n; j++)
                    if(upVisit[j])
                        cnt++;

                if(cnt == n + 1)
                    ans++;
            }

            sb.append("#").append(tc).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }
}