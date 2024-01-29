import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Node{
    int r;
    int c;

    public Node(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

class Solution{
    static int T, n, k, ans, maxH;
    static int[][] map = new int[15][15];
    static List<Node> topNodes;
    static boolean[][] visit = new boolean[15][15];
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, -1, 0, 1};

    static boolean isIn(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < n;
    }
    static void dfs(int r, int c, int len){
        visit[r][c] = true;
        for(int d = 0; d < 4; d++) {
            int new_r = r + dr[d], new_c = c + dc[d];
            if (isIn(new_r, new_c) && !visit[new_r][new_c] && map[new_r][new_c] < map[r][c]) {
                dfs(new_r, new_c, len + 1);
            }
        }
        ans = Math.max(ans, len);
        visit[r][c] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());
        for(int tc = 1; tc <= T; tc++){
            st = new StringTokenizer(br.readLine(), " ");
            topNodes = new ArrayList<>();
            maxH = 0;
            ans = 0;
            n = Integer.parseInt(st.nextToken()); k = Integer.parseInt(st.nextToken());
            for(int i = 0; i < n; i++){
                st = new StringTokenizer(br.readLine(), " ");
                for(int j = 0; j < n; j++){
                    map[i][j] = Integer.parseInt(st.nextToken());
                    maxH = Math.max(maxH, map[i][j]);
                }
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    if(map[i][j] == maxH)
                        topNodes.add(new Node(i, j));

            for (Node topNode : topNodes) {
                dfs(topNode.r, topNode.c, 1);
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(int a = 1; a <= k; a++){
                        map[i][j] -= a;
                        for (Node topNode : topNodes) {
                            if(map[topNode.r][topNode.c] == maxH)
                                dfs(topNode.r, topNode.c, 1);
                        }
                        map[i][j] += a;
                    }

                }
            }

            sb.append("#").append(tc).append(" ").append(ans).append('\n');

        }
        System.out.println(sb);
    }
}
/**
 * 조금 애매한 부분
 * 만약 최대 봉우리가 1개 있는 경우에 여기를 깍으면 최대 봉우리의 maxH가 달라질 수 있음
 * 하지만 최대 봉우리에서 출발하고 그 다음에 깍는 선후 관계이기 때문에 최대 봉우리를 깍는다는게 말이 안되는 듯?
 */